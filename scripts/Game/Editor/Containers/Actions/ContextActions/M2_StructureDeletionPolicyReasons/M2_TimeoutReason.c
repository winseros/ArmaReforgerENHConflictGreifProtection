class M2_TimeoutReason : M2_StructureDeletionPolicyReason
{
	protected int m_iTimeoutSeconds;
	
	int GetTimeoutSeconds()
	{
		return m_iTimeoutSeconds;
	}
	
	void M2_TimeoutReason(int timeoutSeconds)
	{
		m_iTimeoutSeconds = timeoutSeconds;
	}
}