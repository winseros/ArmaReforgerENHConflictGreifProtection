class M2_StructureDeletionPermission
{
	protected ref array<ref M2_StructureDeletionPolicy> m_aPolicies;
	
	bool CanDeleteCampaignStruture(IEntity structure, out M2_StructureDeletionPolicyReason reason)
	{
		M2_StructureDeletionPolicyContext context = new M2_StructureDeletionPolicyContext();
		foreach (M2_StructureDeletionPolicy policy : m_aPolicies)
		{
			policy.EvaluatePolicy(structure, context);
			if (!context.CanDeleteStructure())
			{
				reason = context.GetReason();
				return false;
			}
		}
		return true;
	}
	
	void M2_StructureDeletionPermission(notnull array<ref M2_StructureDeletionPolicy> policies)
	{
		m_aPolicies = policies;
	}
}