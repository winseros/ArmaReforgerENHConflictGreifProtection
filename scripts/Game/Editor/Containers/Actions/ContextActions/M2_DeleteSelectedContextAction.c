[BaseContainerProps(), SCR_BaseContainerCustomTitleUIInfo("m_Info")]
modded class SCR_DeleteSelectedContextAction
{
	protected ref M2_StructureDeletionPermission m_StructureDeletionPermission = new M2_StructureDeletionPermission({
		new M2_ForbidTimeoutDeletionPolicy(timeoutSeconds: 600),
		new M2_ForbidRankDeletionPolicy(ranksIncrementForDelete: 1),
		new M2_ForbidFilledSupplyDepotDeletionPolicy(),
		new M2_ForbidStructureDeletionWithResourceLossPolicy()
	});
	
	override bool CanBeShown(SCR_EditableEntityComponent hoveredEntity, notnull set<SCR_EditableEntityComponent> selectedEntities, vector cursorWorldPosition, int flags)
	{
		if (IsCampaignGameMode())
		{
			return true;
		}
		else
		{
			return super.CanBeShown(hoveredEntity, selectedEntities, cursorWorldPosition, flags);
		}
	}
	
	override bool CanBePerformed(SCR_EditableEntityComponent selectedEntity, vector cursorWorldPosition, int flags)
	{
		bool result = super.CanBePerformed(selectedEntity, cursorWorldPosition, flags);
		
		if (result && IsCampaignGameMode())
		{
			IEntity owner = selectedEntity.GetOwner();
			if (owner && IsCampaignObject(owner))
			{
				M2_StructureDeletionPolicyReason reason;
				result = m_StructureDeletionPermission.CanDeleteCampaignStruture(owner, reason);
				if (!result && reason)
				{
					// not the true place to notify the player
					// but the best I could plug into
					NotifyLocalPlayerIfClient(reason);
				}
			}
		}
		
		return result;
	}
	
	protected bool IsCampaignObject(IEntity structure)
	{
		int budget;
		return M2_EditorBudgetHelper.GetBudgetValue(structure, EEditableEntityBudget.CAMPAIGN, budget);
	}
	
	protected void NotifyLocalPlayerIfClient(M2_StructureDeletionPolicyReason reason)
	{
		if (RplSession.Mode() != RplMode.Dedicated)
		{
			M2_NotificationHelper.NotifyLocalPlayer(reason);
		}
	}

	protected bool IsCampaignGameMode()
	{
		return SCR_GameModeCampaignMP.Cast(GetGame().GetGameMode());
	}
}