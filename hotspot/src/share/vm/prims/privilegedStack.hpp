/*
 * Copyright 1997-2000 Sun Microsystems, Inc.  All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa Clara,
 * CA 95054 USA or visit www.sun.com if you need additional information or
 * have any questions.
 *
 */

class PrivilegedElement VALUE_OBJ_CLASS_SPEC {
 private:
  klassOop  _klass;                // klass for method
  oop       _privileged_context;   // context for operation
  intptr_t*     _frame_id;             // location on stack
  PrivilegedElement* _next;        // Link to next one on stack
 public:
  void initialize(vframeStream* vf, oop context, PrivilegedElement* next, TRAPS);
  void oops_do(OopClosure* f);
  intptr_t* frame_id() const           { return _frame_id; }
  oop  privileged_context() const  { return _privileged_context; }
  oop  class_loader() const        { return instanceKlass::cast(_klass)->class_loader(); }
  oop  protection_domain() const   { return instanceKlass::cast(_klass)->protection_domain(); }
  PrivilegedElement *next() const  { return _next; }

  // debugging (used for find)
  void print_on(outputStream* st) const   PRODUCT_RETURN;
  bool contains(address addr)             PRODUCT_RETURN0;
};
