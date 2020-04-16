// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

#pragma once

#include <EditorUndoClient.h>
#include <Templates/SharedPointer.h>
#include <Toolkits/AssetEditorToolkit.h>
#include <UObject/GCObject.h>

class FSpawnTabArgs;
class ISlateStyle;
class IToolkitHost;
class SDockTab;
class UXMLAsset;

/* The FXMLAssetEditorToolkit
*/
class FXMLAssetEditorToolkit
	: public FAssetEditorToolkit
	, public FEditorUndoClient
	, public FGCObject
{
	public:

		/**
		 * Creates and initializes a new instance.
		 *
		 * @param InStyle The style set to use.
		 */
		FXMLAssetEditorToolkit(const TSharedRef<ISlateStyle>& InStyle);

		/** Virtual destructor. */
		virtual ~FXMLAssetEditorToolkit();

	public:

		/**
		 * Initializes the editor tool kit.
		 *
		 * @param InTextAsset The UTextAsset asset to edit.
		 * @param InMode The mode to create the toolkit in.
		 * @param InToolkitHost The toolkit host.
		 */
		void Initialize(UXMLAsset* InXMLAsset, const EToolkitMode::Type InMode, const TSharedPtr<IToolkitHost>& InToolkitHost);

	public:

		//~ FAssetEditorToolkit interface
		
		// When the user opens the Asset editor and clicks help this link opens in the default browser
		virtual FString GetDocumentationLink() const override;

		virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
		virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;

	public:

		//~ IToolkit interface

		virtual FText GetBaseToolkitName() const override;
		virtual FName GetToolkitFName() const override;
		virtual FLinearColor GetWorldCentricTabColorScale() const override;
		virtual FString GetWorldCentricTabPrefix() const override;

	public:

		//~ FGCObject interface

		virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	
	protected:

		//~ FEditorUndoClient interface

		virtual void PostUndo(bool bSuccess) override;
		virtual void PostRedo(bool bSuccess) override;

	private:

		/** Callback for spawning the Properties tab. */
		TSharedRef<SDockTab> HandleTabManagerSpawnTab(const FSpawnTabArgs& Args, FName TabIdentifier);

	private:
		UXMLAsset* XMLAsset;

		/** Pointer to the style set to use for toolkits. */
		TSharedRef<ISlateStyle> Style;
};
