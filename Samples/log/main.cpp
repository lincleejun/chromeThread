#include <iostream>
#include "base/logging.h"
#include "base/command_line.h"

bool InitLog()
{
    bool bSucceed = logging::InitLogging(L"debug.log",
                logging::LOG_TO_BOTH_FILE_AND_SYSTEM_DEBUG_LOG,
                logging::DONT_LOCK_LOG_FILE,
                logging::APPEND_TO_OLD_LOG_FILE,
                logging::DISABLE_DCHECK_FOR_NON_OFFICIAL_RELEASE_BUILDS);
    return bSucceed;
}

void LogTest()
{
    LOG(INFO) << "LOG_WARNING\r\n";
    logging::SetShowErrorDialogs(true);
    //LOG(FATAL) << "Fatal Error" << std::endl;
    logging::SetShowErrorDialogs(false);
}

void DLogTest()
{
    int i = 3;
    LOG_ASSERT(i > 3);
    DLOG_ASSERT(i > 3);
}
void PLogTest()
{
    PLOG(ERROR) << "Couldn't do foo";
    DPLOG(ERROR) << "Couldn't do foo";
    PLOG_IF(ERROR, 1) << "Couldn't do foo";
    DPLOG_IF(ERROR, 0) << "Couldn't do foo";
    PCHECK(1) << "Couldn't do foo";
    DPCHECK(1) << "Couldn't do foo";
}

int main(int argc, char* argv[])
{
    CommandLine::Init(argc, argv);
    InitLog();
    LogTest();
    DLogTest();
    PLogTest();
    return 0;
}