class M2_ForbidTimeoutDeletionPolicy : M2_StructureDeletionPolicy
{
	protected int m_iTimeoutSeconds;
	
	override void EvaluatePolicy(IEntity entity, notnull M2_StructureDeletionPolicyContext context)
	{
		SCR_CampaignServiceComponent comp = SCR_CampaignServiceComponent.Cast(entity.FindComponent(SCR_CampaignServiceComponent));
		if (!comp)
			return;
		
		SCR_CampaignBase base = comp.GetParentBase();
		if (!base || base.GetIsHQ())
			return;
		
		float lastCaptureTime = base.GetLastOwnerChangeTime();
		float timeSinceLastCapture = Math.Round((Replication.Time() - lastCaptureTime) / 1000);
		if (timeSinceLastCapture < m_iTimeoutSeconds)
			context.ForbidDeletion(new M2_TimeoutReason(m_iTimeoutSeconds - timeSinceLastCapture));
	}
	
	void M2_ForbidTimeoutDeletionPolicy(int timeoutSeconds)
	{
		m_iTimeoutSeconds = timeoutSeconds;
	}
}