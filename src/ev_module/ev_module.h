#ifndef _E_EV_MODULE_H_
#define _E_EV_MODULE_H_

#if defined(__cplusplus)
namespace evoluti {
#endif
struct ev_mod_ver {
    unsigned char major;
    unsigned char minor;
    unsigned char patch;
};
#if defined(__cplusplus)
}
#endif

#if defined(_cplusplus)
#define EV_MODULE_NAME(_name) const char evoluti::ev_mod_name[] = _name
#else
#define EV_MODULE_NAME(_name) const char EV_MOD_NAME[] = _name
#endif

#if defined(__cplusplus)
#define EV_MODULE_VERSION(_mj, _mn, _pt) const struct ev_mod_ver evoluti::ev_mod_ver = {_mj, _mn, _pt}
#else
#define EV_MODULE_VERSION(_mj, _mn, _pt) const struct ev_mod_ver EV_MOD_VER = {_mj, _mn, _pt}
#endif

#if defined(__cplusplus)
#define EV_MODULE_ID(_id) const unsigned char evoluti::ev_mod_id[] = _id
#else
#define EV_MODULE_ID(_id) const unsigned char EV_MOD_ID[] = _id
#endif

#endif /* _E_EV_MODULE_H_ */