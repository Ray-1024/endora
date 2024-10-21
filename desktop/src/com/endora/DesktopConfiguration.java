package com.endora;

import com.badlogic.gdx.backends.lwjgl3.Lwjgl3ApplicationConfiguration;

public class DesktopConfiguration extends Lwjgl3ApplicationConfiguration {
    public DesktopConfiguration() {
        setTitle("Endora");
        setForegroundFPS(60);
        setIdleFPS(5);
        setFullscreenMode(Lwjgl3ApplicationConfiguration.getDisplayMode());
    }
}
