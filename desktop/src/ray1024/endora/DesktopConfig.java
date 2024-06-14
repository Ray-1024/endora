package ray1024.endora;

import com.badlogic.gdx.backends.lwjgl3.Lwjgl3ApplicationConfiguration;

public class DesktopConfig extends Lwjgl3ApplicationConfiguration {
    public DesktopConfig() {
        setTitle("Endora");
        setForegroundFPS(60);
        setFullscreenMode(Lwjgl3ApplicationConfiguration.getDisplayMode());
    }
}
