[BaseContainerProps(), SCR_BaseContainerCustomTitleEnum(ENotification, "m_NotificationKey")]
class M2_NotificationTime : SCR_NotificationDisplayData
{
	override string GetText(SCR_NotificationData data)
	{
		int totalSeconds;
		data.GetParams(totalSeconds);
		
		int days, hours, minutes, seconds;
		SCR_DateTimeHelper.GetDayHourMinuteSecondFromSeconds(totalSeconds, days, hours, minutes, seconds);
		string timeStr = SCR_FormatHelper.GetTimeFormatting(days, hours, minutes, seconds, ETimeFormatParam.DAYS | ETimeFormatParam.HOURS);
		data.SetNotificationTextEntries(timeStr);
		
		return super.GetText(data);
	}
}