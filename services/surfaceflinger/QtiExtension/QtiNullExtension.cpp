/* Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */
#include "QtiNullExtension.h"

namespace android::surfaceflingerextension {

QtiNullExtension::QtiNullExtension() {
    ALOGI("QtiNullExtension enabled");
}

void QtiNullExtension::qtiInit(SurfaceFlinger* flinger) {}
QtiSurfaceFlingerExtensionIntf* QtiNullExtension::qtiPostInit(
        android::impl::HWComposer& hwc, Hwc2::impl::PowerAdvisor* powerAdvisor,
        scheduler::VsyncConfiguration* vsyncConfig) {
    return this;
}
void QtiNullExtension::qtiSetVsyncConfiguration(scheduler::VsyncConfiguration* vsyncConfig) {}
void QtiNullExtension::qtiSetTid() {}
bool QtiNullExtension::qtiGetHwcDisplayId(const sp<DisplayDevice>& display,
                                          uint32_t* hwcDisplayId) {
    return false;
}
void QtiNullExtension::qtiHandlePresentationDisplaysEarlyWakeup(size_t updatingDisplays,
                                                                uint32_t layerStackId) {}

bool QtiNullExtension::qtiIsInternalPresentationDisplays() {
    return false;
}
bool QtiNullExtension::qtiIsWakeUpPresentationDisplays() {
    return false;
}
void QtiNullExtension::qtiResetEarlyWakeUp() {}
void QtiNullExtension::qtiSetDisplayExtnActiveConfig(uint32_t displayId, uint32_t activeConfigId) {}
void QtiNullExtension::qtiUpdateDisplayExtension(uint32_t displayId, uint32_t configId,
                                                 bool connected) {}
void QtiNullExtension::qtiUpdateDisplaysList(sp<DisplayDevice> display, bool addDisplay) {}
void QtiNullExtension::qtiUpdateOnProcessDisplayHotplug(uint32_t hwcDisplayId,
                                                        hal::Connection connection,
                                                        PhysicalDisplayId id) {}
void QtiNullExtension::qtiUpdateOnComposerHalHotplug(hal::HWDisplayId hwcDisplayId,
                                                     hal::Connection connection) {}
void QtiNullExtension::qtiUpdateInternalDisplaysPresentationMode() {}

/*
 * Methods that call the FeatureManager APIs.
 */
bool QtiNullExtension::qtiIsExtensionFeatureEnabled(QtiFeature feature) {
    return false;
}

/*
 * Methods used by SurfaceFlinger DisplayHardware.
 */
status_t QtiNullExtension::qtiSetDisplayElapseTime(
        std::chrono::steady_clock::time_point earliestPresentTime) const {
    return OK;
}

/*
 * Methods that call the DisplayExtension APIs.
 */
void QtiNullExtension::qtiSendCompositorTid() {}
void QtiNullExtension::qtiSendInitialFps(uint32_t fps) {}
void QtiNullExtension::qtiNotifyDisplayUpdateImminent() {}
void QtiNullExtension::qtiSetContentFps(uint32_t contentFps) {}
void QtiNullExtension::qtiSetEarlyWakeUpConfig(const sp<DisplayDevice>& display,
                                               hal::PowerMode mode) {}
void QtiNullExtension::qtiUpdateVsyncConfiguration() {}

/*
 * Methods that call FrameScheduler APIs.
 */
void QtiNullExtension::qtiUpdateFrameScheduler() {}

/*
 * Methods that call the IDisplayConfig APIs.
 */
status_t QtiNullExtension::qtiGetDebugProperty(string prop, string* value) {
    return OK;
}
status_t QtiNullExtension::qtiIsSupportedConfigSwitch(const sp<IBinder>& displayToken, int config) {
    return OK;
}
} // namespace android::surfaceflingerextension
