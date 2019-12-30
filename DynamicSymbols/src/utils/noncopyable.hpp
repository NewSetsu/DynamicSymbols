#ifndef SRC_UTILS_NONCOPYABLE_HPP_
#define SRC_UTILS_NONCOPYABLE_HPP_

namespace utils {

namespace base {

class noncopyable {
  protected:
    noncopyable() = default;

    ~noncopyable() = default;

    noncopyable(const noncopyable &) = delete;

    noncopyable &operator=(const noncopyable &) = delete;

};

class nonmoveable {
  protected:
    nonmoveable() = default;

    ~nonmoveable() = default;

    nonmoveable(nonmoveable&&) = delete;

    nonmoveable& operator=(nonmoveable&&) = delete;
};


} /* namespace utils */

typedef base::noncopyable noncopyable;
typedef base::nonmoveable nonmoveable;

} /* namespace utils */

#endif /* SRC_UTILS_NONCOPYABLE_HPP_ */
