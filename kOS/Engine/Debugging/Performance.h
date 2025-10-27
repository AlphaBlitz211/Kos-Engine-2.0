/******************************************************************/
/*!
\file      Peformance.h
\author    Jaz Winn Ng
\par       jazwinn.ng@digipen.edu
\date      Sept 28, 2025
\brief     Singleton class to track and manage performance metrics such as FPS, delta time,
		   and performance data for system and script components.

Copyright (C) 2025 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************/
#pragma once
#include "Config/pch.h"

class Peformance
{
public:
    static std::shared_ptr<Peformance> GetInstance() {
        if (!m_InstancePtr)
        {
            m_InstancePtr = std::make_shared<Peformance>();
        }
        return m_InstancePtr;
    }

    const std::unordered_map<std::string, float>& GetSystemPerformance() const
    {
        return m_SystemPerformance;
    }

    const std::unordered_map<std::string, float>& GetScriptPerformance() const
    {
        return m_ScriptPerformance;
    }


    float GetFPS() const
    {
        return m_fps;

    }

    void SetDeltaTime(float delta)
    {
        m_detaTime = delta;
        m_fps = 1 / delta;
    }

    float GetDeltaTime() const
    {
        return m_detaTime;
    }


    // Optional: for convenience, add/modify a single system performance entry
    void SetSystemValue(const std::string& key, float value)
    {
        m_SystemPerformance[key] = value;
    }

    void SetScriptValue(const std::string& key, float value)
    {
        m_ScriptPerformance[key] = value;
    }

private:
	static std::shared_ptr<Peformance> m_InstancePtr;
    std::unordered_map<std::string, float> m_SystemPerformance;
    std::unordered_map<std::string, float> m_ScriptPerformance;
    float m_fps{};
    float m_detaTime{};
    
};

