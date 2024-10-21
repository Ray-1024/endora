package com.endora;

import com.badlogic.gdx.backends.lwjgl3.Lwjgl3Application;

// Please note that on macOS your application needs to be started with the -XstartOnFirstThread JVM argument
public class DesktopLauncher {
    public static void main(String[] arg) {
        new Lwjgl3Application(new MainGame(), new DesktopConfiguration());
    }
}
