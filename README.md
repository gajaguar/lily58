# Lily58 keymap

> By [@gajaguar](https://github.com/gajaguar)

Keymap for Lily58 PRO keyboard with an encoder from [MysticMechs](https://mysticmechs.com).

## Build prerequisite

This keymap overrides `render_logo()` in `keymap.c` to show plain text on the
boot splash instead of the default Mechboards bitmap. That only compiles if
`keyboards/mechboards/lily58/pro/pro.c`'s own `render_logo()` is marked
`weak`, e.g.:

```diff
 #ifdef OLED_ENABLE
-void render_logo(void) {
+__attribute__((weak)) void render_logo(void) {
     static const char PROGMEM pro_logo[] = {
```

Without this, the build fails with `multiple definition of 'render_logo'`.
Apply the patch to your local qmk_firmware checkout before compiling, until
it's merged upstream.