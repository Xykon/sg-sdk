/** -------------------------------------------------------------------------- *
 * @copyright Copyright (c) 2023-2024 SG Wireless - All Rights Reserved
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files(the “Software”), to deal
 * in the Software without restriction, including without limitation the rights
 * to use,  copy,  modify,  merge, publish, distribute, sublicense, and/or sell
 * copies  of  the  Software,  and  to  permit  persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED “AS IS”,  WITHOUT WARRANTY OF ANY KIND,  EXPRESS OR
 * IMPLIED,  INCLUDING BUT NOT LIMITED TO  THE  WARRANTIES  OF  MERCHANTABILITY
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS  OR  COPYRIGHT  HOLDERS  BE  LIABLE FOR ANY CLAIM,  DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN  CONNECTION WITH  THE SOFTWARE OR  THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 * --------------------------------------------------------------------------- *
 * @copyright Copyright (c) 2022, Pycom Limited.
 *
 * This software is licensed under the GNU GPL version 3 or any
 * later version, with permitted additional terms. For more information
 * see the Pycom Licence v1.0 document supplied with this file, or
 * available at https://www.pycom.io/opensource/licensing
 * 
 * @author  Ahmed Sabry (Pycom)
 * 
 * @brief   Adds some helper micropython functions
 * --------------------------------------------------------------------------- *
 */

/** -------------------------------------------------------------------------- *
 * includes
 * --------------------------------------------------------------------------- *
 */
#include "mp_lite_if.h"
#include "py/objstr.h"

/** -------------------------------------------------------------------------- *
 * APIs implementations
 * --------------------------------------------------------------------------- *
 */
const char* mp_get_string(mp_obj_t obj)
{
    if(obj == MP_OBJ_NULL)
    {
        return NULL;
    }

    const char* str;
    if(mp_obj_is_str(obj)) {
        if(mp_obj_is_qstr(obj)) {
            size_t str_len;
            str = (const char*)qstr_data(MP_OBJ_QSTR_VALUE(obj), &str_len);
        } else {
            str = (const char*)(((mp_obj_str_t *)MP_OBJ_TO_PTR(obj))->data);
        }
        return str;
    } else {
    }
    return NULL;
}

/* --- end of file ---------------------------------------------------------- */
