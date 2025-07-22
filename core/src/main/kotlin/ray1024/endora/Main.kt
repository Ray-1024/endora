package ray1024.endora

import com.badlogic.gdx.Game
import com.badlogic.gdx.Gdx
import com.badlogic.gdx.Input
import com.badlogic.gdx.utils.ScreenUtils
import ray1024.endora.screen.*

/** [com.badlogic.gdx.ApplicationListener] implementation shared by all platforms. */
class Main : Game(), EndoraScreenManager {
    private val loadingScreen: LoadingScreen = LoadingScreen(this)
    private val mainMenuScreen: MainMenuScreen = MainMenuScreen(this)
    private val gameScreen: GameScreen = GameScreen(this)
    private val settingsScreen: SettingsScreen = SettingsScreen(this)

    override fun create() {
        setScreen(loadingScreen)
    }

    override fun render() {
        ScreenUtils.clear(0f, 0f, 0f, 0f)
        if (Gdx.input.isKeyPressed(Input.Keys.ESCAPE)) {
            Gdx.app.exit()
        }
        if (Gdx.input.isKeyPressed(Input.Keys.LEFT))
            showLoadingScreen()
        if (Gdx.input.isKeyPressed(Input.Keys.DOWN))
            showMainMenuScreen()
        if (Gdx.input.isKeyPressed(Input.Keys.RIGHT))
            showGameScreen()
        if (Gdx.input.isKeyPressed(Input.Keys.UP))
            showSettingsScreen()
        super.render()
    }

    override fun showGameScreen() {
        setScreen(gameScreen)
    }

    override fun showSettingsScreen() {
        setScreen(settingsScreen)
    }

    override fun showMainMenuScreen() {
        setScreen(mainMenuScreen)
    }

    override fun showLoadingScreen() {
        setScreen(loadingScreen)
    }
}
