class M2_NotificationHelper
{
	static void NotifyLocalPlayer(notnull M2_StructureDeletionPolicyReason reason)
	{
		M2_SuppliesLossReason suppliesLossReason = M2_SuppliesLossReason.Cast(reason);
		if (suppliesLossReason)
		{
			SCR_NotificationsComponent.SendLocal(ENotification.M2_DELETE_FAILED_RESOURCE_LOSS, suppliesLossReason.GetLossValue());
			return;
		}
		M2_RankReason rankReason = M2_RankReason.Cast(reason);
		if (rankReason)
		{
			FactionManager fm = GetGame().GetFactionManager();
			Faction faction = fm.GetFactionByKey(rankReason.GetFactionKey());
			int factionIndex = fm.GetFactionIndex(faction);
			SCR_NotificationsComponent.SendLocal(ENotification.M2_DELETE_FAILED_RANK, factionIndex, rankReason.GetRequiredRank());
			return;
		}
		M2_TimeoutReason timeoutReason = M2_TimeoutReason.Cast(reason);
		if (timeoutReason)
		{			
			SCR_NotificationsComponent.SendLocal(ENotification.M2_DELETE_FAILED_TIME, timeoutReason.GetTimeoutSeconds());
			return;
		}
		Print(string.Format("Unknown reason: %1", reason.Type()), LogLevel.WARNING);
	}
}