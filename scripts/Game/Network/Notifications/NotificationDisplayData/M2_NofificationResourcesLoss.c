[BaseContainerProps(), SCR_BaseContainerCustomTitleEnum(ENotification, "m_NotificationKey")]
class M2_NotificationResourcesLoss : SCR_NotificationDisplayData
{
	override string GetText(SCR_NotificationData data)
	{
		int lossValue;
		data.GetParams(lossValue);
		data.SetNotificationTextEntries(lossValue.ToString());
		return super.GetText(data);
	}
}