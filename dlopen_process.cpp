void dlopen_process(const char *name, void *handle) {
    //LOGD("dlopen: %s", name);
    if (!il2cpp_handle) {
        if (strstr(name, "libil2cpp.so")) {
            il2cpp_handle = handle;
            LOGI("Got il2cpp handle!");
        }
    }

    if (!libc_handle) {
        if (strstr(name, "libc.so")) {
            libc_handle = handle;
            LOGI("Got libc handle before!");
            void *addr = dlsym(handle, "pthread_create");
            DobbyHook(addr, (void*) new_pthread_create, (void**) &old_pthread_create);
            LOGI("Got libc handle after!");
        }
    }
}

/*
void *il2cpp_handle = NULL;
dlopen_process
libc_handle
bool sub_hack_thread() -> bool sub_hack_thread(void *handle)
HookEntry
    //void *handle = nullptr;
    //LOGD("sdk: %d", android_get_device_api_level());
    //if(android_get_device_api_level() >= __ANDROID_API_M__) {
    //    handle = RET_FUNC2(dlopen, SAFE_CSTR(Const::General::libil2cpp_so), RTLD_NOLOAD);
    //}
*/
