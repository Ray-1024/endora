package ray1024.endora.screen

import com.badlogic.gdx.ScreenAdapter
import com.badlogic.gdx.graphics.Color
import com.badlogic.gdx.utils.ScreenUtils

class SettingsScreen(
    private val endoraScreenManager: EndoraScreenManager
) : ScreenAdapter() {
    override fun render(delta: Float) {
        ScreenUtils.clear(Color.YELLOW)
    }
}
