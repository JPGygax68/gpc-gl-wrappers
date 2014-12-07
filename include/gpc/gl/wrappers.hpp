#pragma once

#include <stdexcept>

namespace gpc {

    namespace gl {

        template<typename F, typename... Args>
        auto func(const char *text, int line, const char *file, F fn, Args&&... args) -> decltype(fn(std::forward<Args>(args)...))
        {
            auto result = fn(std::forward<Args>(args)...);
            //if (result == static_cast<decltype(result)>(0)) throw std::runtime_error(text);
            auto err = glGetError();
            if (err != 0) throw std::runtime_error(std::string(text) + " failed at line " + std::to_string(line) + " in file " + file);
            return result;
        }

        template<typename P, typename... Args>
        auto proc(P pr, Args&&... args) -> decltype(pr(std::forward<Args>(args)...))
        {
            pr(std::forward<Args>(args)...);
            auto err = glGetError();
            if (err != 0) throw std::runtime_error(std::string(text) + " failed at line " + std::to_string(line) + " in file " + file);
        }

    } // ns gl
    
} // ns gpc

#if !defined(GLDEBUG) && defined(_DEBUG)
#define GLDEBUG
#endif

#if defined (GLDEBUG)  

#define CALL_GL(fn, ...) gpc::gl::func(#fn, __LINE__, __FILE__, fn, __VA_ARGS__)
#define EXEC_GL(pr, ...) gpc::gl::proc(#pr, __LINE__, __FILE__, pr, __VA_ARGS__)

#else

#define CALL_GL(fn, ...) fn(__VA_ARGS__)
#define EXEC_GL(pr, ...) pr(__VA_ARGS__)

#endif  

