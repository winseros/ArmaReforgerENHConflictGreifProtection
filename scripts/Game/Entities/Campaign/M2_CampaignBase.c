modded class SCR_CampaignBase
{
	[RplProp()]
	protected float m_fLastOwnerChangeTime = 0;
	
	float GetLastOwnerChangeTime()
	{
		return m_fLastOwnerChangeTime;
	}
	
	protected override void OnOwningFactionChanged(Faction newFaction)
	{
		super.OnOwningFactionChanged(newFaction);
		m_fLastOwnerChangeTime = Replication.Time();
		Replication.BumpMe();
	}
}