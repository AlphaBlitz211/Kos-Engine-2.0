/******************************************************************/
/*!
\file      Imgui_meta_window.cpp
\author    Ng Jaz winn, jazwinn.ng , 2301502
\par       jazwinn.ng@digipen.edu
\date      Oct 02, 2025
\brief     This file reads and saves the meta data of the selected asset.
		   It also allows editing of the meta data fields.



Copyright (C) 2024 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
*/
/********************************************************************/



#include "Editor.h"
#include "Config/pch.h"
#include "AssetManager/AssetDatabase.h"

void gui::ImGuiHandler::DrawAssetInspector() {

    
    
    ImGui::Begin("Asset Inspector");

    if(!AssetPath.empty()) {

        ImGui::TextDisabled("Selected File %s", AssetPath.filename().string().c_str());
        selectedAsset.ApplyFunction(DrawComponents{ selectedAsset.Names() });
       

        float windowWidth = ImGui::GetContentRegionAvail().x; // Available width inside window
        float buttonWidth = 100.0f; // Width of your button

        ImGui::SetCursorPosX((windowWidth - buttonWidth) * 0.5f); // Center horizontally
        if (ImGui::Button("Save", ImVec2(buttonWidth, 0))) {
            // Button clicked
            Serialization::WriteJsonFile(AssetPath.string(), &selectedAsset);
        }

	}




    ImGui::End();

}