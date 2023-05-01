class M2_RankReason : M2_StructureDeletionPolicyReason 
{
	protected FactionKey m_FactionKey;
	protected ECharacterRank m_iRequiredRank;

	FactionKey GetFactionKey()
	{
		return m_FactionKey;
	}
	
	ECharacterRank GetRequiredRank()
	{
		return m_iRequiredRank;
	}
	
	void M2_RankReason(FactionKey factionKey, ECharacterRank requiredRank)
	{
		m_FactionKey = factionKey;
		m_iRequiredRank = requiredRank;
	}
}