class UO_FW_ExportLoadoutToProfileAttribute: ComboPreview {
    attributeLoad="";
    attributeSave="";
	class Controls: Controls {
		class Title: Title {};
		class Value: ctrlEdit {
			idc=100;
            x="48 * (pixelW * pixelGrid * 	0.50)";
			w="(	60 - 	5) * (pixelW * pixelGrid * 	0.50)";
			h="5 * (pixelH * pixelGrid * 	0.50)";
		};
		class Preview: ctrlButtonPictureKeepAspect {
			idc=101;
            x="(	48 + 	60 - 	5) * (pixelW * pixelGrid * 	0.50)";
			w="0.99 * 	5 * (pixelW * pixelGrid * 	0.50)";
			h="5 * (pixelH * pixelGrid * 	0.50)";
			text="\a3\3DEN\Data\Attributes\ComboPreview\play_ca.paa";
			onMouseButtonClick="\
				_ctrlButton = _this select 0;\
				_ctrlGroup = ctrlParentControlsGroup _ctrlButton;\
				_ctrlEdit = _ctrlGroup controlsgroupctrl 100;\
				_name = ctrlText _ctrlEdit;\
				[_name,false] call UO_FW_fnc_ExportLoadoutSettings;\
			";
		};
	};
};
