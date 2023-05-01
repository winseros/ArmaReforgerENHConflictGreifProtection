class M2_EditorBudgetHelper
{
	static bool GetConstructionRefudValue(IEntity structure, out int structureRefundValue)
	{
		SCR_EditableEntityComponent editableEntComp = SCR_EditableEntityComponent.Cast(structure.FindComponent(SCR_EditableEntityComponent));
		if (!editableEntComp)
			return false;
		
		EEditableEntityBudget budgetType;
		float refundRatio;
		if (!TakeCampaignBudget(budgetType, refundRatio))
			return false;
		
		int budgetValue;
		if (!GetBudgetValue(structure, budgetType, budgetValue))
			return false;
		
		structureRefundValue = Math.Round(budgetValue * refundRatio);
		return true;
	}
	
	static bool GetBudgetValue(IEntity structure, EEditableEntityBudget budgetType, out int budgetValue)
	{
		SCR_EditableEntityComponent editableEntComp = SCR_EditableEntityComponent.Cast(structure.FindComponent(SCR_EditableEntityComponent));
		if (!editableEntComp)
			return false;
		
		array<ref SCR_EntityBudgetValue> budgetValues = {};
		if (!editableEntComp.GetEntityBudgetCost(budgetValues))
			return false;		
		
		SCR_EntityBudgetValue bv;
		if (!FindBudget(budgetValues, budgetType, bv))
			return false;
		
		budgetValue = bv.GetBudgetValue();
		return true;
	}
	
	private static bool FindBudget(notnull array<ref SCR_EntityBudgetValue> budgets, EEditableEntityBudget budgetType, out SCR_EntityBudgetValue budget)
	{
		foreach (SCR_EntityBudgetValue b : budgets)
		{
			if (b.GetBudgetType() == budgetType)
			{
				budget = b;
				return true;
			}
		}
		
		return false;
	}
	
	private static bool TakeCampaignBudget(out EEditableEntityBudget budgetType, out float refundRatio)
	{
		SCR_CampaignBuildingManagerComponent comp = SCR_CampaignBuildingManagerComponent.Cast(GetGame().GetGameMode().FindComponent(SCR_CampaignBuildingManagerComponent));
		if (!comp)
			return false;
		
		budgetType = comp.GetBudgetType();
		refundRatio = comp.GetCompositionRefundPercentage() / 100;
		return true;
	}
}