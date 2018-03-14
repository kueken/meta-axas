DESCRIPTION = "V3DDRIVER for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
PACKAGE_ARCH = "${MACHINE_ARCH}"

PROVIDES = "virtual/libgles2 virtual/egl libnxpl.so libnexus.so libv3ddriver.so libGLESv2.so libEGL.so"
DEPENDS = "axas-libgles-headers"

PV = "${SRCDATE}"
PR = "r0"

SRC_URI = "http://222.239.254.238/e4hd/libgles/${MACHINE}-libgles-${SRCDATE}.zip"

S = "${WORKDIR}"

do_configure() {
}

do_compile() {
}

do_install_append() {
	install -d ${D}${libdir}
	install -m 0755 ${S}/libnxpl.so ${D}${libdir}/
	install -m 0755 ${S}/libnexus.so ${D}${libdir}/
	install -m 0755 ${S}/libv3ddriver.so ${D}${libdir}/
	ln -s libv3ddriver.so ${D}${libdir}/libEGL.so
	ln -s libv3ddriver.so ${D}${libdir}/libGLESv2.so
}

FILES_${PN} = "/usr/lib/*"
FILES_${PN}-dev = "/usr/include/*"

RPROVIDES_${PN} = "virtual/libgles2 virtual/egl libnxpl.so libnexus.so libv3ddriver.so libGLESv2.so libEGL.so"

INSANE_SKIP_${PN} += "already-stripped dev-so"