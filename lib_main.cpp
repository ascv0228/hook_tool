__attribute__((constructor))
void lib_main() {
    LOGD(OBFUSCATE("Own lib has been loaded"));

    byPass();

    pthread_t ptid;
    VOID_FUNC4(pthread_create, &ptid, (pthread_attr_t*)NULL, &hack_thread, (void*)NULL);
}
