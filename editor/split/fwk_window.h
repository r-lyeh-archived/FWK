// -----------------------------------------------------------------------------
// window framework
// - rlyeh, public domain
//
// @todo: window_cursor(ico);
// @todo: if WINDOW_PORTRAIT && exist portrait monitor, use that instead of primary one
// @todo: WINDOW_TRAY

enum WINDOW_FLAGS {
    WINDOW_MSAA2 = 0x02,
    WINDOW_MSAA4 = 0x04,
    WINDOW_MSAA8 = 0x08,

    WINDOW_SQUARE = 0x20,
    WINDOW_PORTRAIT = 0x40,
    WINDOW_LANDSCAPE = 0x80,
    WINDOW_ASPECT = 0x100, // keep aspect
    WINDOW_FIXED = 0x200, // disable resizing

    WINDOW_VSYNC = 0,
    WINDOW_VSYNC_ADAPTIVE = 0x1000,
    WINDOW_VSYNC_DISABLED = 0x2000,
};

API bool     window_create(float scale, unsigned flags);
API bool     window_create_from_handle(void *handle, float scale, unsigned flags);

API int      window_frame_begin();
API void     window_frame_end();
API void     window_frame_swap();
API int      window_swap(); // single function that combines above functions (desktop only)

API void     window_loop(void (*function)(void* loopArg), void* loopArg ); // run main loop function continuously (emscripten only)
API void     window_loop_exit(); // exit from main loop function (emscripten only)

API void     window_title(const char *title);
API void     window_icon(const char *file_icon);
API vec2     window_canvas();
API void*    window_handle();
API char*    window_stats();

API uint64_t window_frame();
API int      window_width();
API int      window_height();
API double   window_aspect();
API double   window_time();
API double   window_delta();
API double   window_fps();

// API bool  window_hook(void (*func)(), void* userdata); // deprecated
// API void  window_unhook(void (*func)()); // deprecated

API void     window_focus(); // window attribute api using haz catz language for now
API int      window_has_focus();
API void     window_fullscreen(int enabled);
API int      window_has_fullscreen();
API void     window_cursor(int visible);
API int      window_has_cursor();
API void     window_pause(int paused);
API int      window_has_pause();
API void     window_visible(int visible);
API int      window_has_visible();

API void     window_lock_aspect(unsigned numer, unsigned denom);
API void     window_unlock_aspect();
API void     window_lock_fps(float fps);
API void     window_unlock_fps();

API void     window_screenshot(const char* filename_png);
