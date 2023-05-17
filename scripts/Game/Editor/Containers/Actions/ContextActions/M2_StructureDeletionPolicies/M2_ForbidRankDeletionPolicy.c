class M2_ForbidRankDeletionPolicy : M2_StructureDeletionPolicy 
{
	protected int m_iRanksIncrmentForDelete;
	
	override void EvaluatePolicy(IEntity entity, notnull M2_StructureDeletionPolicyContext context)
	{		
		if (!entity.FindComponent(SCR_CampaignServiceComponent))
			return;//don't anger on fortifications
		
		FactionKey playerFactionKey;
		SCR_EServicePointType playerRank;
		if (!M2_CharacterRankHelper.GetPlayerRank(playerFactionKey, playerRank))
			return;
		
		int requiredRankValue;
		if (!M2_EditorBudgetHelper.GetBudgetValue(entity, EEditableEntityBudget.RANK_CORPORAL, requiredRankValue))
		{
			if (!M2_EditorBudgetHelper.GetBudgetValue(entity, EEditableEntityBudget.RANK_SERGEANT, requiredRankValue))
			{
				requiredRankValue = SCR_ECharacterRank.PRIVATE;
			}
		}
		
		requiredRankValue += m_iRanksIncrmentForDelete;
		
		if (playerRank < requiredRankValue)
			context.ForbidDeletion(new M2_RankReason(playerFactionKey, requiredRankValue));
	}
	
	void M2_ForbidRankDeletionPolicy(int ranksIncrementForDelete)
	{
		m_iRanksIncrmentForDelete = ranksIncrementForDelete;
	}
}