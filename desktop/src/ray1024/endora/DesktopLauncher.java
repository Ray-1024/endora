package ray1024.endora;

import com.badlogic.gdx.backends.lwjgl3.Lwjgl3Application;

// Please note that on macOS your application needs to be started with the -XstartOnFirstThread JVM argument
public class DesktopLauncher extends Lwjgl3Application {

    public DesktopLauncher() {
        super(new Cortex(), new DesktopConfig());
    }

    public static void main(String[] arg) {
        new DesktopLauncher();
    }
}
