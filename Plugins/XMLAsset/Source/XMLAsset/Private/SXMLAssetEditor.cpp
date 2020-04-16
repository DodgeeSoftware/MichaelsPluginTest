// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

// PLUGIN Includes
#include "SXMLAssetEditor.h"
#include "XMLAssetEditorSettings.h"
#include "XMLAsset.h"

#define LOCTEXT_NAMESPACE "SXMLAssetEditor"

 SXMLAssetEditor::~SXMLAssetEditor()
{
	 FCoreUObjectDelegates::OnObjectPropertyChanged.RemoveAll(this);
}

void SXMLAssetEditor::Construct(const FArguments& InArgs, UXMLAsset* InXMLAsset, const TSharedRef<ISlateStyle>& InStyle)
{
	this->XMLAsset = InXMLAsset;

	auto Settings = GetDefault<UXMLAssetEditorSettings>();

	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(STextBlock) // Make a Label
				.Text(FText::FromString("SButton")) // Set the Text on the Label
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SButton)
				.Text(FText::FromString("SButton")) // Set the Text on the Label
			]
		]
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(STextBlock) // Make a Label
				.Text(FText::FromString("SCheckBox")) // Set the Text on the Label
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SCheckBox)
			]
		]
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("SComboBox")) // Set the Text on the Label
		//	]
		//	//+ SHorizontalBox::Slot()
		//	//[
		//		// TODO: https://answers.unrealengine.com/questions/384327/slate-scombobox-example.html
		//		//SNew(SComboBox)
		//	//]
		//]
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(STextBlock) // Make a Label
				.Text(FText::FromString("SComboButton")) // Set the Text on the Label
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SComboButton)
			]
		]
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("SEditableComboBox")) // Set the Text on the Label
		//	]
		//	// TODO: This isn't straight forward to implement
		//	//+ SHorizontalBox::Slot()
		//	//[
		//		//SNew(SEditableComboBox)
		//	//]
		//]
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(STextBlock) // Make a Label
				.Text(FText::FromString("SEditableTextBox")) // Set the Text on the Label
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SEditableTextBox)
			]
		]
		// DO NOT UNCOMMENT CAUSES ASSET EDITOR TO HANG
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("SExpandableButton")) // Set the Text on the Label
		//	]
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(SExpandableButton)
		//	]
		//]
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(STextBlock) // Make a Label
				.Text(FText::FromString("SHyperlink")) // Set the Text on the Label
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SHyperlink).Text(FText::FromString("https://youtube.com/dodgeesoftware"))
			]
		]
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("SInputKeySelector")) // Set the Text on the Label
		//	]
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(SInputKeySelector)
		//	]
		//]
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(STextBlock) // Make a Label
				.Text(FText::FromString("SMenuAnchor")) // Set the Text on the Label
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SMenuAnchor)
			]
		]
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("SMultiLineEditableTextBox")) // Set the Text on the Label
		//	]
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(SMultiLineEditableTextBox)
		//	]
		//]
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("SNumericDropDown")) // Set the Text on the Label
		//	]
		//	// TODO: NumericDropDown seems more involved to implement
		//	//+ SHorizontalBox::Slot()
		//	//[
		//		//SNew(SNumericDropDown) 
		//	//]
		//]
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("SMultiLineEditableTextBox")) // Set the Text on the Label
		//	]
		//	// TODO: SNumericEntryBox seems more involved to implement	
		//	//+ SHorizontalBox::Slot()
		//	//[
		//		//SNew(SNumericEntryBox)
		//	//]
		//]
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("SRichTextHyperlink")) // Set the Text on the Label
		//	]
		//	// TODO: Function does not take 1 arguments
		//	//+ SHorizontalBox::Slot()
		//	//[
		//		//SNew(SRichTextHyperlink)
		//	//]
		//]
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(STextBlock) // Make a Label
				.Text(FText::FromString("SRotatorInputBox")) // Set the Text on the Label
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SRotatorInputBox)
			]
		]
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("SSpinBox")) // Set the Text on the Label
		//	]
		//	// TODO: SSpinBox seems more involved to implement	
		//	//+ SHorizontalBox::Slot()
		//	//[
		//		//SNew(SSpinBox)
		//	//]
		//]		
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("SSubMenuHandler")) // Set the Text on the Label
		//	]
		//	// TODO: function does not take 1 arguments
		//	//+ SHorizontalBox::Slot()
		//	//[
		//		//SNew(SSubMenuHandler)
		//	//]
		//]
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(STextBlock) // Make a Label
				.Text(FText::FromString("SSuggestionTextBox")) // Set the Text on the Label
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SSuggestionTextBox)
			]
		]
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("STextComboBox")) // Set the Text on the Label
		//	]
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextComboBox)
		//	]
		//]
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("STextComboPopup")) // Set the Text on the Label
		//	]
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextComboPopup)
		//	]
		//]
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("STextEntryPopup")) // Set the Text on the Label
		//	]
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextEntryPopup)
		//	]
		//]
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(STextBlock) // Make a Label
				.Text(FText::FromString("SVectorInputBox")) // Set the Text on the Label
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SVectorInputBox)
			]
		]
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("SVirtualJoystick")) // Set the Text on the Label
		//	]
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(SVirtualJoystick)
		//	]
		//]
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(STextBlock) // Make a Label
				.Text(FText::FromString("SVirtualKeyboardEntry")) // Set the Text on the Label
			]
			+ SHorizontalBox::Slot()
			[
				// NOTE: Doesn't seem to do anything in its present form
				SNew(SVirtualKeyboardEntry)
			]
		]
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(STextBlock) // Make a Label
				.Text(FText::FromString("SVolumeControl")) // Set the Text on the Label
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SVolumeControl)
			]
		]
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(STextBlock) // Make a Label
				.Text(FText::FromString("SSlider")) // Set the Text on the Label
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SSlider)
			]
		]
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(SHorizontalBox) // Use a horizontal Layout
				+ SHorizontalBox::Slot() // Add a new slot to the horizonal layout
				[
					SNew(STextBlock) // Make a Label
					.Text(FText::FromString("TextBox1")) // Set the Text on the Label
				]
				+ SHorizontalBox::Slot() // Add a new slot to the horizonal layout
				[
					/* NOTE: Notice how I use SAssigNew here instead of SNew, this
						is so that we can create the Object and assign a local (class member)
						reference to it. This allows us to query its value
						during onclick events etc */
					SAssignNew(this->TextBox1, SEditableTextBox) // Make a TextBox
				]
			]
		]
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(STextBlock) // Make a Label
				.Text(FText::FromString("SObjectPropertyEntryBox")) // Set the Text on the Label
				// NOTE: Requires PropertyEditor module to be added to the *.cs file
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SObjectPropertyEntryBox)
			]
		]
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("SClassPropertyEntryBox")) // Set the Text on the Label
		//		// NOTE: Requires PropertyEditor module to be added to the *.cs file
		//	]
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(SClassPropertyEntryBox)
		//	]
		//]
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("SProperty")) // Set the Text on the Label
		//		// NOTE: Requires PropertyEditor module to be added to the *.cs file
		//	]
		//	+ SHorizontalBox::Slot()
		//	[
		//		// TODO: function does not take 1 arguments
		//		SNew(SProperty)
		//	]
		//]
		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		SNew(STextBlock) // Make a Label
		//		.Text(FText::FromString("SMaterialSlotWidget")) // Set the Text on the Label
		//		// NOTE: Requires PropertyEditor module to be added to the *.cs file
		//	]
		//	+ SHorizontalBox::Slot()
		//	[
		//		// TODO: function does not take 1 arguments
		//		SNew(SMaterialSlotWidget)
		//	]
		//]



		//+ SVerticalBox::Slot()
		//[
		//	SNew(SHorizontalBox)
		//	+ SHorizontalBox::Slot()
		//	[
		//		PropertyCustomizationHelpers::MakeUseSelectedButton( FSimpleDelegate::CreateSP( this, &SXMLAssetEditor::zzz ), FText()) // , IsEnabledAttribute - this was the last parameter
		//	]
		//	+ SHorizontalBox::Slot()
		//	[
		//		//PropertyCustomizationHelpers::MakeDocumentationButton(this);
		//	]
		//]
		
		+ SVerticalBox::Slot()
			//.FillHeight(1.0f)
			[
				SAssignNew(EditableTextBox, SMultiLineEditableTextBox)
					.BackgroundColor((Settings != nullptr) ? Settings->BackgroundColor : FLinearColor::White)
					.Font((Settings != nullptr) ? Settings->Font : FSlateFontInfo())
					.ForegroundColor((Settings != nullptr) ? Settings->ForegroundColor : FLinearColor::Black)
					.Margin((Settings != nullptr) ? Settings->Margin : 4.0f)
					.OnTextChanged(this, &SXMLAssetEditor::HandleEditableTextBoxTextChanged)
					.OnTextCommitted(this, &SXMLAssetEditor::HandleEditableTextBoxTextCommitted)
					.Text(this->XMLAsset->Text)
			]
	];
	
	PropertyCustomizationHelpers::MakeResetButton(
		FSimpleDelegate::CreateSP(this, &SXMLAssetEditor::zzz));

	// Grab Asset Tools Module
	//IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<ContentBrow>("AssetTools").Get();	
	//FContentBrowserModule& ContentBrowser = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	//ContentBrowser.Get()

	FCoreUObjectDelegates::OnObjectPropertyChanged.AddSP(this, &SXMLAssetEditor::HandleTextAssetPropertyChanged);
}

void SXMLAssetEditor::HandleEditableTextBoxTextChanged(const FText& NewText)
{

}

void SXMLAssetEditor::HandleEditableTextBoxTextCommitted(const FText& Comment, ETextCommit::Type CommitType)
{

}

void SXMLAssetEditor::HandleTextAssetPropertyChanged(UObject* Object, FPropertyChangedEvent& PropertyChangedEvent)
{

}

#undef LOCTEXT_NAMESPACE