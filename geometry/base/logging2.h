

#ifndef _BASE_LOGGING2_H_
#define _BASE_LOGGING2_H_

#include <base/logging.h>

#define VLOG(x) if((x)>0){} else LOG(FATAL)

#endif