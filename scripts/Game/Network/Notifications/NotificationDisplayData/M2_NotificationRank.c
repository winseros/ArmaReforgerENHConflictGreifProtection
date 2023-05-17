[BaseContainerProps(), SCR_BaseContainerCustomTitleEnum(ENotification, "m_NotificationKey")]
class M2_NotificationRank : SCR_NotificationDisplayData
{
	override string GetText(SCR_NotificationData data)
	{
		int factionIndex, rank;
		data.GetParams(factionIndex, rank);
		
		SCR_FactionManager fm = SCR_FactionManager.Cast(GetGame().GetFactionManager());
		if (fm)
		{
			SCR_Faction fc = SCR_Faction.Cast(fm.GetFactionByIndex(factionIndex));
			if (fc)
			{
				string rankName = fc.GetRankName(rank);
				data.SetNotificationTextEntries(rankName);
			}
		}
		return super.GetText(data);
	}
}