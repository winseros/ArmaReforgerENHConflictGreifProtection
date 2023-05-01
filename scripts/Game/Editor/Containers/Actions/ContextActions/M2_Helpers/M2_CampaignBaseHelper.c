class M2_CampaignBaseHelper
{
	static bool GetBaseSupplies(notnull SCR_CampaignBase base, out int currentSupplies, out int baseOwnCapacity, out int baseMaxCapacity)
	{
		SCR_CampaignSuppliesComponent suppliesComp = SCR_CampaignSuppliesComponent.Cast(base.FindComponent(SCR_CampaignSuppliesComponent));
		if (!suppliesComp)
			return false;
		
		baseMaxCapacity = suppliesComp.GetSuppliesMax();
		
		if (baseMaxCapacity > SCR_GameModeCampaignMP.SUPPLY_DEPOT_CAPACITY)
			baseOwnCapacity = baseMaxCapacity - SCR_GameModeCampaignMP.SUPPLY_DEPOT_CAPACITY;
		else
			baseOwnCapacity = baseMaxCapacity;
		
		currentSupplies = suppliesComp.GetSupplies();
		
		return true;
	}
}