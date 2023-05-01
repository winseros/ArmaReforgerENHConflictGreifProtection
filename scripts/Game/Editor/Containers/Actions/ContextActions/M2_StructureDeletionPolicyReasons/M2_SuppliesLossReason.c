class M2_SuppliesLossReason : M2_StructureDeletionPolicyReason
{
	protected int m_iSuppliesLossValue;
	
	int GetLossValue()
	{
		return m_iSuppliesLossValue;
	}
	
	void M2_SuppliesLossReason(int lossValue)
	{
		m_iSuppliesLossValue = lossValue;
	}
}