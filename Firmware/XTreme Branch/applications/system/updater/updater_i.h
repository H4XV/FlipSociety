#pragma once

#include "views/updater_main.h"
#include "util/update_task.h"

#include <furi.h>
#include <gui/gui.h>
#include <gui/view_stack.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/popup.h>
#include <gui/scene_manager.h>
#include <gui/modules/widget.h>
#include <storage/storage.h>
#include <notification/notification_app.h>
#include <update_util/update_operation.h>

#ifdef __cplusplus
extern "C" {
#endif

#define UPDATER_APP_TICK 500

typedef enum {
    UpdaterViewMain,
    UpdaterViewWidget,
} UpdaterViewEnum;

typedef enum {
    UpdaterCustomEventUnknown,
    UpdaterCustomEventStartUpdate,
    UpdaterCustomEventRetryUpdate,
    UpdaterCustomEventCancelUpdate,
    UpdaterCustomEventSdUnmounted,
} UpdaterCustomEvent;

typedef struct {
    // GUI
    Gui* gui;
    NotificationApp* notification;
    SceneManager* scene_manager;
    ViewDispatcher* view_dispatcher;
    Storage* storage;

    UpdaterMainView* main_view;

    UpdateManifest* loaded_manifest;
    UpdatePrepareResult preparation_result;

    UpdateTask* update_task;
    Widget* widget;
    FuriString* startup_arg;
    int32_t idle_ticks;
} Updater;

Updater* updater_alloc(char* arg);

void updater_free(Updater* updater);

#ifdef __cplusplus
}
#endif
