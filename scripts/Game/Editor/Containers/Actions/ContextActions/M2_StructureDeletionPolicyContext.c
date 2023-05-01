class M2_StructureDeletionPolicyContext
{
	protected bool m_bCanDeleteStructure = true;
	
	protected ref M2_StructureDeletionPolicyReason m_Reason;
	
	bool CanDeleteStructure()
	{
		return m_bCanDeleteStructure;
	}
	
	M2_StructureDeletionPolicyReason GetReason()
	{
		return m_Reason;
	}
	
	void ForbidDeletion(notnull M2_StructureDeletionPolicyReason reason)
	{
		m_bCanDeleteStructure = false;
		m_Reason = reason;
	}
}