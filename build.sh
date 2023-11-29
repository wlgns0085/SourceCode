meson setup build
ninja -C build
DESTDIR=./../bin ninja -C build install