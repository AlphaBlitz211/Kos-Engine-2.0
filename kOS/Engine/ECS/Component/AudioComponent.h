#pragma once
/******************************************************************/
/*!
\file      AudioComponent.h
\author    Chiu Jun Jie
\par       junjie.c@digipen.edu
\date      Oct 03, 2025
\brief     This file contains the audio data


Copyright (C) 2025 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
*/
/********************************************************************/
#ifndef AUDIOCOM_H
#define AUDIOCOM_H

#include "Component.h"

namespace ecs {

    // FMOD Core
    struct AudioFile {

		bool loop{ false };
		bool playOnStart{ false };
		bool hasPlayed{ false };
		bool isBGM{ false };
		bool isSFX{ true };
		bool hasChanged = false;
        bool lastLoopState{ false };
		float volume{ 1.0f };
		float pan{ 0.0f };
        float lastVolume{ -1.0f };
        std::string name;


        bool requestPlay{ false };

        std::string audioGUID{};

        //3D Spatial for core
        bool  use3D{ false };        // if true, ignore pan and use 3D
        float minDistance{ 1.0f };   // full volume within this distance
        float maxDistance{ 30.0f };  // 0 volume over this distance

        void* channelPtr{ nullptr }; // Running channel for looping mover

        REFLECTABLE(AudioFile, audioGUID, volume, loop, playOnStart, hasPlayed, pan, isBGM, isSFX)
    };


    //FMOD Studio
    struct StudioEventRef {
        std::string eventPath;       
        bool  playOnStart{ false };
        bool  loop{ false };
        float volume{ 1.0f };
        bool  is3D{ true };          // event tag as 3D in Studio? 
        bool  requestPlay{ false }; 

        void* instancePtr{ nullptr };

        REFLECTABLE(StudioEventRef,
            eventPath, playOnStart, loop, volume, is3D
        )
    };


    class AudioComponent : public Component {
    public:
        std::vector<AudioFile> audioFiles;          // Core clip (TO REPLACE)
        std::vector<StudioEventRef> studioEvents;   // Studio event

        REFLECTABLE(AudioComponent, audioFiles, studioEvents)
    };
}
#endif AUDIOCOM_H