class M2_CharacterRankHelper
{
	static bool GetPlayerRank(out FactionKey factionKey, out ECharacterRank rank) 
	{
		if (RplSession.Mode() == RplMode.Dedicated)
			return false;
		
		IEntity player = GetGame().GetPlayerController().GetControlledEntity();
		rank = SCR_CharacterRankComponent.GetCharacterRank(player);
		
		FactionAffiliationComponent factionComponent = FactionAffiliationComponent.Cast(player.FindComponent(FactionAffiliationComponent));
		if (!factionComponent)
			return false;
		
		factionKey = factionComponent.GetAffiliatedFaction().GetFactionKey();
		return true;
	}
}