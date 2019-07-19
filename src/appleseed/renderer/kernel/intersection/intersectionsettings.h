
//
// This source file is part of appleseed.
// Visit https://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2013 Francois Beaune, Jupiter Jazz Limited
// Copyright (c) 2014-2018 Francois Beaune, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

// appleseed.renderer headers.
#include "renderer/global/globaltypes.h"

// appleseed.foundation headers.
#include "foundation/math/beziercurve.h"
#include "foundation/math/intersection/raytrianglemt.h"
#include "foundation/math/matrix.h"

// Standard headers.
#include <cstddef>

namespace renderer
{

//
// Assembly tree settings.
//

// Maximum number of assemblies per leaf.
const size_t InstanceTreeMaxLeafSize = 1;

// Relative cost of traversing an interior node.
const double InstanceTreeInteriorNodeTraversalCost = 1.0;

// Relative cost of intersecting an assembly.
const double InstanceTreeTriangleIntersectionCost = 10.0;


//
// Triangle tree settings.
//

// Triangle format used for storage.
typedef foundation::TriangleMT<GScalar> GTriangleType;

// Triangle format used for intersection.
typedef foundation::TriangleMT<double> TriangleType;
typedef foundation::TriangleMTSupportPlane<double> TriangleSupportPlaneType;

// Maximum number of triangles per leaf.
const size_t TriangleTreeDefaultMaxLeafSize = 2;

// Relative cost of traversing an interior node.
const GScalar TriangleTreeDefaultInteriorNodeTraversalCost(1.0);

// Relative cost of intersecting a triangle.
const GScalar TriangleTreeDefaultTriangleIntersectionCost(1.0);

// Number of bins used during SBVH construction.
const size_t TriangleTreeDefaultBinCount = 256;

// Define this symbol to enable reordering the nodes of triangle trees for better
// locality of reference. Requires a lot of temporary memory for minimal results.
#undef RENDERER_TRIANGLE_TREE_REORDER_NODES

// Depth of a subtree in the van Emde Boas node layout.
const size_t TriangleTreeSubtreeDepth = 3;

// Size of the triangle tree access cache.
const size_t TriangleTreeAccessCacheLines = 128;
const size_t TriangleTreeAccessCacheWays = 2;

// Size of the stack (in number of nodes) used during traversal.
const size_t TriangleTreeStackSize = 64;


//
// Miscellaneous settings.
//

// If defined, an adaptive procedure is used to offset intersection points.
// If left undefined, a fixed, constant-time procedure is used. The adaptive
// procedure handles degenerate cases better but is slightly slower. It must
// be used when the triangle model is set to Moller-Trumbore (MT).
#define RENDERER_ADAPTIVE_OFFSET

}   // namespace renderer
