class UO_FW_SelfActions {
    displayName = "Self Action Settings";
    collapsed = 1;
    class Attributes {
        class UO_FW_SelfActions_Enable {
            property = "UO_FW_SelfActions_Enable";
            displayName = "Self Actions Enable";
            tooltip = "Enable Self Actions";
            control = "CheckboxState";
            expression = UO_FW_SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class UO_FW_SelfActions_CheckColour_Enabled {
            property = "UO_FW_SelfActions_CheckColour_Enabled";
            displayName = "Team Colour Action";
            tooltip = "Enable Team Colour Action";
            control = "Checkbox";
            expression = UO_FW_SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class UO_FW_SelfActions_CheckMap_Enabled {
            property = "UO_FW_SelfActions_CheckMap_Enabled";
            displayName = "View Map Action";
            tooltip = "Enable View Map Action";
            control = "Checkbox";
            expression = UO_FW_SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class UO_FW_SelfActions_CutGrass_Enabled {
            property = "UO_FW_SelfActions_CutGrass_Enabled";
            displayName = "Cut Grass Action";
            tooltip = "Enable Cut Grass Action";
            control = "Checkbox";
            expression = UO_FW_SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class UO_FW_SelfActions_ParaFlares_Enabled {
            property = "UO_FW_SelfActions_ParaFlares_Enabled";
            displayName = "Launch ParaFlare Action";
            tooltip = "Enable Launch ParaFlare Action";
            control = "Checkbox";
            expression = UO_FW_SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class UO_FW_SelfActions_ParaFlare_Brightness {
            property = "UO_FW_SelfActions_ParaFlare_Brightness";
            displayName = "ParaFlare Brightness";
            tooltip = "Sets the brightness of paraflares";
            control = "UO_FW_SelfActions_ParaFlare_Brightness_Slider";
            expression = UO_FW_SCENARIO_EXPRESSION;
            defaultValue = "15";
        };
    };
};
