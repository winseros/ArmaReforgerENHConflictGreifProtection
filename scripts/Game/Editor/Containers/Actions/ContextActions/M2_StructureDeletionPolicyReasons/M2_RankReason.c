class M2_RankReason : M2_StructureDeletionPolicyReason 
{
	protected FactionKey m_FactionKey;
	protected SCR_ECharacterRank m_iRequiredRank;

	FactionKey GetFactionKey()
	{
		return m_FactionKey;
	}
	
	SCR_ECharacterRank GetRequiredRank()
	{
		return m_iRequiredRank;
	}
	
	void M2_RankReason(FactionKey factionKey, SCR_ECharacterRank requiredRank)
	{
		m_FactionKey = factionKey;
		m_iRequiredRank = requiredRank;
	}
}