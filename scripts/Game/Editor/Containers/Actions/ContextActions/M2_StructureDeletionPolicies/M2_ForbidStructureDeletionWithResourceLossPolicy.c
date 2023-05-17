class M2_ForbidStructureDeletionWithResourceLossPolicy : M2_StructureDeletionPolicy
{
	override void EvaluatePolicy(IEntity entity, notnull M2_StructureDeletionPolicyContext context)
	{
		SCR_CampaignServiceComponent comp = SCR_CampaignServiceComponent.Cast(entity.FindComponent(SCR_CampaignServiceComponent));
		if (!comp)
			return;
		
		SCR_CampaignBase base = comp.GetParentBase();
		if (!base)
			return;
		
		int baseSupplies, baseOwnCapacity, baseMaxCapacity;
		if (!M2_CampaignBaseHelper.GetBaseSupplies(base, baseSupplies, baseOwnCapacity, baseMaxCapacity))
			return;
		
		if (comp.GetType() == SCR_EServicePointType.SUPPLY_DEPOT)
			baseMaxCapacity = baseOwnCapacity;
		
		int refundValue;
		if (!M2_EditorBudgetHelper.GetConstructionRefudValue(entity, refundValue))
			return;		

		if (baseSupplies + refundValue > baseMaxCapacity)
			context.ForbidDeletion(new M2_SuppliesLossReason(baseSupplies + refundValue - baseMaxCapacity));
	}
}