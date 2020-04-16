// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

#pragma once

// UNREAL ENGINE Includes
#include <Templates/SharedPointer.h>
#include <Widgets/DeclarativeSyntaxSupport.h>
#include <Widgets/SCompoundWidget.h>
#include <Widgets/Input/SMultiLineEditableTextBox.h>
#include <Fonts/SlateFontInfo.h>
#include <Internationalization/Text.h>
#include <UObject/Class.h>

#include <Widgets/Colors/SColorBlock.h>
#include <Widgets/Colors/SColorGradingWheel.h>
#include <Widgets/Colors/SColorSpectrum.h>
#include <Widgets/Colors/SColorWheel.h>

#include <Widgets/Docking/SDockableTab.h>
#include <Widgets/Docking/SDockTab.h>
#include <Widgets/Docking/SDockTabStack.h>

#include <Widgets/Images/SImage.h>
#include <Widgets/Images/SSpinningImage.h>
#include <Widgets/Images/SThrobber.h>


#include <Widgets/Input/SButton.h>
#include <Widgets/Input/SCheckBox.h>
#include <Widgets/Input/SComboBox.h>
#include <Widgets/Input/SComboButton.h>
#include <Widgets/Input/SEditableComboBox.h>
#include <Widgets/Input/SEditableTextBox.h>
#include <Widgets/Input/SExpandableButton.h>
#include <Widgets/Input/SHyperlink.h>
#include <Widgets/Input/SInputKeySelector.h>
#include <Widgets/Input/SMenuAnchor.h>
#include <Widgets/Input/SMultiLineEditableTextBox.h>
#include <Widgets/Input/SNumericDropDown.h>
#include <Widgets/Input/SNumericEntryBox.h>
#include <Widgets/Input/SRichTextHyperlink.h>
#include <Widgets/Input/SRotatorInputBox.h>
#include <Widgets/Input/SSearchBox.h>
#include <Widgets/Input/SSlider.h>
#include <Widgets/Input/SSpinBox.h>
#include <Widgets/Input/SSubMenuHandler.h>
#include <Widgets/Input/SSuggestionTextBox.h>
#include <Widgets/Input/STextComboBox.h>
#include <Widgets/Input/STextComboPopup.h>
#include <Widgets/Input/STextEntryPopup.h>
#include <Widgets/Input/SVectorInputBox.h>
#include <Widgets/Input/SVirtualJoystick.h>
#include <Widgets/Input/SVirtualKeyboardEntry.h>
#include <Widgets/Input/SVolumeControl.h>

#include <Widgets/LayerManager/SLayerManager.h>
#include <Widgets/LayerManager/STooltipPresenter.h>

#include <Widgets/Layout/SBackgroundBlur.h>
#include <Widgets/Layout/SBorder.h>
#include <Widgets/Layout/SBox.h>
#include <Widgets/Layout/SConstraintCanvas.h>
#include <Widgets/Layout/SDPIScaler.h>
#include <Widgets/Layout/SEnableBox.h>
#include <Widgets/Layout/SExpandableArea.h>
#include <Widgets/Layout/SFxWidget.h>
#include <Widgets/Layout/SGridPanel.h>
#include <Widgets/Layout/SHeader.h>
#include <Widgets/Layout/SMenuOwner.h>
#include <Widgets/Layout/SMissingWidget.h>
#include <Widgets/Layout/SPopup.h>
#include <Widgets/Layout/SResponsiveGridPanel.h>
#include <Widgets/Layout/SSafeZone.h>
#include <Widgets/Layout/SScaleBox.h>
#include <Widgets/Layout/SScissorRectBox.h>
#include <Widgets/Layout/SScrollBar.h>
#include <Widgets/Layout/SScrollBarTrack.h>
#include <Widgets/Layout/SScrollBorder.h>
#include <Widgets/Layout/SScrollBox.h>
#include <Widgets/Layout/SSeparator.h>
#include <Widgets/Layout/SSpacer.h>
#include <Widgets/Layout/SSplitter.h>
#include <Widgets/Layout/SUniformGridPanel.h>
#include <Widgets/Layout/SWidgetSwitcher.h>
#include <Widgets/Layout/SWindowTitleBarArea.h>
#include <Widgets/Layout/SWrapBox.h>

#include <Widgets/Navigation/SBreadcrumbTrail.h>

//#include <Widgets/Notifications/GlobalNotification.h>
//#include <Widgets/Notifications/INotificationWidget.h>
#include <Widgets/Notifications/SErrorHint.h>
#include <Widgets/Notifications/SErrorText.h>
#include <Widgets/Notifications/SNotificationList.h>
#include <Widgets/Notifications/SPopUpErrorText.h>
#include <Widgets/Notifications/SProgressBar.h>

//#include <Widgets/Text/ISlateEditableTextWidget.h>
#include <Widgets/Text/SInlineEditableTextBlock.h>
#include <Widgets/Text/SlateEditableTextLayout.h>
#include <Widgets/Text/SlateEditableTextTypes.h>
//#include <Widgets/Text/SlateTextBlockLayout.h>
#include <Widgets/Text/SMultiLineEditableText.h>
#include <Widgets/Text/SRichTextBlock.h>
#include <Widgets/Text/STextBlock.h>

#include <Widgets/Views/SExpanderArrow.h>
#include <Widgets/Views/SHeaderRow.h>
#include <Widgets/Views/SListView.h>
#include <Widgets/Views/STableRow.h>
#include <Widgets/Views/STableViewBase.h>
#include <Widgets/Views/STileView.h>
#include <Widgets/Views/STreeView.h>

// NOTE: Cannot use this one, private means its not exported
//#include <Editor/PropertyEditor/Private/UserInterface/PropertyEditor/SPropertyAssetPicker.h>
#include <Editor/PropertyEditor/Public/PropertyCustomizationHelpers.h> // TODO: Super Interesting Header need to solve linker issue then use it

#include <Editor/ContentBrowser/Public/ContentBrowserModule.h>

class FText;
class ISlateStyle;
class UXMLAsset;

/* The SXMLAssetEditor is a Custom Widget made from the 
	base Class SCompount Widget. It comprises the 
	GUI and associated logic for the XML Asset Editor */
class SXMLAssetEditor : public SCompoundWidget
{
	void zzz() {}
	
	// *********
	// * SLATE *
	// *********
	public:
		SLATE_BEGIN_ARGS(SXMLAssetEditor) { }
		SLATE_END_ARGS()

	public:
		// Destructor
		virtual ~SXMLAssetEditor();

		// Construct
		void Construct(const FArguments& InArgs, UXMLAsset* InXMLAsset, const TSharedRef<ISlateStyle>& InStyle);

	protected:
		// Callback for text changes in the editable text box.
		void HandleEditableTextBoxTextChanged(const FText& NewText);
		// Callback for committed text in the editable text box.
		void HandleEditableTextBoxTextCommitted(const FText& Comment, ETextCommit::Type CommitType);
		// Callback for property changes in the text asset.
		void HandleTextAssetPropertyChanged(UObject* Object, FPropertyChangedEvent& PropertyChangedEvent);

	protected:
		// Holds the editable text box widget
		TSharedPtr<SMultiLineEditableTextBox> EditableTextBox;
		// TextBox 1
		TSharedPtr<SEditableTextBox> TextBox1;
		// Pointer to the UXMLAsset that is being edited
		UXMLAsset* XMLAsset;
};
