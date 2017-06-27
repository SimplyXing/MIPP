#include "mipp.h"

// ------------------------------------------------------------------------------------------------------- ARM NEON-128
// --------------------------------------------------------------------------------------------------------------------
#if defined(__ARM_NEON__) || defined(__ARM_NEON)

	// ---------------------------------------------------------------------------------------------------------- loadu
	template <>
	inline reg loadu<float>(const float *mem_addr) {
		return vld1q_f32(mem_addr);
	}

	template <>
	inline reg loadu<int32_t>(const int32_t *mem_addr) {
		return (reg) vld1q_s32(mem_addr);
	}

	template <>
	inline reg loadu<int16_t>(const int16_t *mem_addr) {
		return (reg) vld1q_s16((int16_t*) mem_addr);
	}

	template <>
	inline reg loadu<int8_t>(const int8_t *mem_addr) {
		return (reg) vld1q_s8((int8_t*) mem_addr);
	}

	// ----------------------------------------------------------------------------------------------------------- load
#ifdef MIPP_ALIGNED_LOADS
	template <>
	inline reg load<float>(const float *mem_addr) {
		return vld1q_f32(mem_addr);
	}

	template <>
	inline reg load<int32_t>(const int32_t *mem_addr) {
		return (reg) vld1q_s32(mem_addr);
	}

	template <>
	inline reg load<int16_t>(const int16_t *mem_addr) {
		return (reg) vld1q_s16((int16_t*) mem_addr);
	}

	template <>
	inline reg load<int8_t>(const int8_t *mem_addr) {
		return (reg) vld1q_s8((int8_t*) mem_addr);
	}
#else
	template <>
	inline reg load<float>(const float *mem_addr) {
		return mipp::loadu<float>(mem_addr);
	}

	template <>
	inline reg load<int32_t>(const int32_t *mem_addr) {
		return mipp::loadu<int32_t>(mem_addr);
	}

	template <>
	inline reg load<int16_t>(const int16_t *mem_addr) {
		return mipp::loadu<int16_t>(mem_addr);
	}

	template <>
	inline reg load<int8_t>(const int8_t *mem_addr) {
		return mipp::loadu<int8_t>(mem_addr);
	}
#endif

	// --------------------------------------------------------------------------------------------------------- storeu
	template <>
	inline void storeu<float>(float *mem_addr, const reg v) {
		vst1q_f32(mem_addr, v);
	}

	template <>
	inline void storeu<int64_t>(int64_t *mem_addr, const reg v) {
		vst1q_f32((float*) mem_addr, v);
	}

	template <>
	inline void storeu<int32_t>(int32_t *mem_addr, const reg v) {
		vst1q_f32((float*) mem_addr, v);
	}

	template <>
	inline void storeu<int16_t>(int16_t *mem_addr, const reg v) {
		vst1q_s16((int16_t*) mem_addr, (int16x8_t) v);
	}

	template <>
	inline void storeu<int8_t>(int8_t *mem_addr, const reg v) {
		vst1q_s8((int8_t*) mem_addr, (int8x16_t) v);
	}

	// ---------------------------------------------------------------------------------------------------------- store
#ifdef MIPP_ALIGNED_LOADS
	template <>
	inline void store<float>(float *mem_addr, const reg v) {
		vst1q_f32(mem_addr, v);
	}

	template <>
	inline void store<int64_t>(int64_t *mem_addr, const reg v) {
		vst1q_f32((float*) mem_addr, v);
	}

	template <>
	inline void store<int32_t>(int32_t *mem_addr, const reg v) {
		vst1q_f32((float*) mem_addr, v);
	}

	template <>
	inline void store<int16_t>(int16_t *mem_addr, const reg v) {
		vst1q_s16((int16_t*) mem_addr, (int16x8_t) v);
	}

	template <>
	inline void store<int8_t>(int8_t *mem_addr, const reg v) {
		vst1q_s8((int8_t*) mem_addr, (int8x16_t) v);
	}
#else
	template <>
	inline void store<float>(float *mem_addr, const reg v) {
		mipp::storeu<float>(mem_addr, v);
	}

	template <>
	inline void store<int32_t>(int32_t *mem_addr, const reg v) {
		mipp::storeu<int32_t>(mem_addr, v);
	}

	template <>
	inline void store<int16_t>(int16_t *mem_addr, const reg v) {
		mipp::storeu<int16_t>(mem_addr, v);
	}

	template <>
	inline void store<int8_t>(int8_t *mem_addr, const reg v) {
		mipp::storeu<int8_t>(mem_addr, v);
	}
#endif

	// ------------------------------------------------------------------------------------------------------------ set
	template <>
	inline reg set<float>(const float vals[nElReg<float>()]) {
		return mipp::load<float>(vals);
	}

	template <>
	inline reg set<int32_t>(const int32_t vals[nElReg<int32_t>()]) {
		return mipp::load<int32_t>(vals);
	}

	template <>
	inline reg set<int16_t>(const int16_t vals[nElReg<int16_t>()]) {
		return mipp::load<int16_t>(vals);
	}

	template <>
	inline reg set<int8_t>(const int8_t vals[nElReg<int8_t>()]) {
		return mipp::load<int8_t>(vals);
	}

	// ----------------------------------------------------------------------------------------------------------- set1
	template <>
	inline reg set1<float>(const float val) {
		return vdupq_n_f32(val);
	}

	template <>
	inline reg set1<int32_t>(const int32_t val) {
		return (reg) vdupq_n_s32(val);
	}

	template <>
	inline reg set1<int16_t>(const int16_t val) {
		return (reg) vdupq_n_s16(val);
	}

	template <>
	inline reg set1<int8_t>(const int8_t val) {
		return (reg) vdupq_n_s8(val);
	}

	// ----------------------------------------------------------------------------------------------------------- set0
	template <>
	inline reg set0<float>() {
		return vdupq_n_f32(0.f);
	}

	template <>
	inline reg set0<int32_t>() {
		return (reg) vdupq_n_s32(0);
	}

	template <>
	inline reg set0<int16_t>() {
		return (reg) vdupq_n_s16(0);
	}

	template <>
	inline reg set0<int8_t>() {
		return (reg) vdupq_n_s8(0);
	}

	// ------------------------------------------------------------------------------------------------------------ low
	template <>
	inline reg_2 low<float>(const reg v) {
		return (reg_2) vget_low_f32((float32x4_t) v);
	}

	template <>
	inline reg_2 low<int32_t>(const reg v) {
		return (reg_2) vget_low_f32((float32x4_t) v);
	}

	template <>
	inline reg_2 low<int16_t>(const reg v) {
		return (reg_2) vget_low_f32((float32x4_t) v);
	}

	template <>
	inline reg_2 low<int8_t>(const reg v) {
		return (reg_2) vget_low_f32((float32x4_t) v);
	}

	// ----------------------------------------------------------------------------------------------------------- high
	template <>
	inline reg_2 high<float>(const reg v) {
		return (reg_2) vget_high_f32((float32x4_t) v);
	}

	template <>
	inline reg_2 high<int32_t>(const reg v) {
		return (reg_2) vget_high_f32((float32x4_t) v);
	}

	template <>
	inline reg_2 high<int16_t>(const reg v) {
		return (reg_2) vget_high_f32((float32x4_t) v);
	}

	template <>
	inline reg_2 high<int8_t>(const reg v) {
		return (reg_2) vget_high_f32((float32x4_t) v);
	}

	// ---------------------------------------------------------------------------------------------------------- cmask
	template <>
	inline reg cmask<float>(const uint32_t val[nElReg<float>()]) {
		int8_t val_bis[nElReg<int8_t>()] = {(int8_t)(val[0]*4 + 0), (int8_t)(val[0]*4 + 1),
		                                    (int8_t)(val[0]*4 + 2), (int8_t)(val[0]*4 + 3),
		                                    (int8_t)(val[1]*4 + 0), (int8_t)(val[1]*4 + 1),
		                                    (int8_t)(val[1]*4 + 2), (int8_t)(val[1]*4 + 3),
		                                    (int8_t)(val[2]*4 + 0), (int8_t)(val[2]*4 + 1),
		                                    (int8_t)(val[2]*4 + 2), (int8_t)(val[2]*4 + 3),
		                                    (int8_t)(val[3]*4 + 0), (int8_t)(val[3]*4 + 1),
		                                    (int8_t)(val[3]*4 + 2), (int8_t)(val[3]*4 + 3)};
		return mipp::set<int8_t>(val_bis);
	}

	template <>
	inline reg cmask<int32_t>(const uint32_t val[nElReg<int32_t>()]) {
		int8_t val_bis[nElReg<int8_t>()] = {(int8_t)(val[0]*4 + 0), (int8_t)(val[0]*4 + 1),
		                                    (int8_t)(val[0]*4 + 2), (int8_t)(val[0]*4 + 3),
		                                    (int8_t)(val[1]*4 + 0), (int8_t)(val[1]*4 + 1),
		                                    (int8_t)(val[1]*4 + 2), (int8_t)(val[1]*4 + 3),
		                                    (int8_t)(val[2]*4 + 0), (int8_t)(val[2]*4 + 1),
		                                    (int8_t)(val[2]*4 + 2), (int8_t)(val[2]*4 + 3),
		                                    (int8_t)(val[3]*4 + 0), (int8_t)(val[3]*4 + 1),
		                                    (int8_t)(val[3]*4 + 2), (int8_t)(val[3]*4 + 3)};
		return mipp::set<int8_t>(val_bis);
	}

	template <>
	inline reg cmask<int16_t>(const uint32_t val[nElReg<int16_t>()]) {
		int8_t val_bis[nElReg<int8_t>()] = {(int8_t)(val[0]*2 + 0), (int8_t)(val[0]*2 + 1),
		                                    (int8_t)(val[1]*2 + 0), (int8_t)(val[1]*2 + 1),
		                                    (int8_t)(val[2]*2 + 0), (int8_t)(val[2]*2 + 1),
		                                    (int8_t)(val[3]*2 + 0), (int8_t)(val[3]*2 + 1),
		                                    (int8_t)(val[4]*2 + 0), (int8_t)(val[4]*2 + 1),
		                                    (int8_t)(val[5]*2 + 0), (int8_t)(val[5]*2 + 1),
		                                    (int8_t)(val[6]*2 + 0), (int8_t)(val[6]*2 + 1),
		                                    (int8_t)(val[7]*2 + 0), (int8_t)(val[7]*2 + 1)};
		return mipp::set<int8_t>(val_bis);
	}

	template <>
	inline reg cmask<int8_t>(const uint32_t val[nElReg<int8_t>()]) {
		int8_t val_bis[nElReg<int8_t>()] = {(int8_t)val[ 0], (int8_t)val[ 1],
		                                    (int8_t)val[ 2], (int8_t)val[ 3],
		                                    (int8_t)val[ 4], (int8_t)val[ 5],
		                                    (int8_t)val[ 6], (int8_t)val[ 7],
		                                    (int8_t)val[ 8], (int8_t)val[ 9],
		                                    (int8_t)val[10], (int8_t)val[11],
		                                    (int8_t)val[12], (int8_t)val[13],
		                                    (int8_t)val[14], (int8_t)val[15]};
		return mipp::set<int8_t>(val_bis);
	}

	// ---------------------------------------------------------------------------------------------------------- shuff
	template <>
	inline reg shuff<float>(const reg v, const reg cm) {
		uint8x8x2_t v2 = {vget_low_u8((uint8x16_t)v), vget_high_u8((uint8x16_t)v)};
		uint8x8_t low  = vtbl2_u8(v2, vget_low_u8 ((uint8x16_t)cm));
		uint8x8_t high = vtbl2_u8(v2, vget_high_u8((uint8x16_t)cm));

		return (reg)vcombine_u8(low, high);
	}

	template <>
	inline reg shuff<int32_t>(const reg v, const reg cm) {
		uint8x8x2_t v2 = {vget_low_u8((uint8x16_t)v), vget_high_u8((uint8x16_t)v)};
		uint8x8_t low  = vtbl2_u8(v2, vget_low_u8 ((uint8x16_t)cm));
		uint8x8_t high = vtbl2_u8(v2, vget_high_u8((uint8x16_t)cm));

		return (reg)vcombine_u8(low, high);	
	}

	template <>
	inline reg shuff<int16_t>(const reg v, const reg cm) {
		uint8x8x2_t v2 = {vget_low_u8((uint8x16_t)v), vget_high_u8((uint8x16_t)v)};
		uint8x8_t low  = vtbl2_u8(v2, vget_low_u8 ((uint8x16_t)cm));
		uint8x8_t high = vtbl2_u8(v2, vget_high_u8((uint8x16_t)cm));

		return (reg)vcombine_u8(low, high);
	}

	template <>
	inline reg shuff<int8_t>(const reg v, const reg cm) {
		uint8x8x2_t v2 = {vget_low_u8((uint8x16_t)v), vget_high_u8((uint8x16_t)v)};
		uint8x8_t low  = vtbl2_u8(v2, vget_low_u8 ((uint8x16_t)cm));
		uint8x8_t high = vtbl2_u8(v2, vget_high_u8((uint8x16_t)cm));

		return (reg)vcombine_u8(low, high);
	}

	// --------------------------------------------------------------------------------------------------------- shuff2
	template <>
	inline reg shuff2<float>(const reg v, const reg cm) {
		return mipp::shuff<float>(v, cm);
	}

	template <>
	inline reg shuff2<int32_t>(const reg v, const reg cm) {
		return mipp::shuff<int32_t>(v, cm);
	}

	template <>
	inline reg shuff2<int16_t>(const reg v, const reg cm) {
		return mipp::shuff<int16_t>(v, cm);
	}

	template <>
	inline reg shuff2<int8_t>(const reg v, const reg cm) {
		return mipp::shuff<int8_t>(v, cm);
	}

	// --------------------------------------------------------------------------------------------------- interleavelo
	template <>
	inline reg interleavelo<int64_t>(const reg v1, const reg v2) {
		// v1  = [a0, b0], v2 = [a1, b1]
		// res = [a0, a1]
		return (reg)vcombine_u64(vget_low_u64((uint64x2_t)v1), vget_low_u64((uint64x2_t)v2));
	}

	template <>
	inline reg interleavelo<float>(const reg v1, const reg v2) {
		// v1  = [a0, b0, c0, d0], v2 = [a1, b1, c1, d1]
		// res = [a0, a1, b0, b1]
		uint32x2x2_t res = vzip_u32(vget_low_u32((uint32x4_t)v1), vget_low_u32((uint32x4_t)v2));
		return (reg)vcombine_u32(res.val[0], res.val[1]);
	}

	template <>
	inline reg interleavelo<int32_t>(const reg v1, const reg v2) {
		// v1  = [a0, b0, c0, d0], v2 = [a1, b1, c1, d1]
		// res = [a0, a1, b0, b1]
		uint32x2x2_t res = vzip_u32(vget_low_u32((uint32x4_t)v1), vget_low_u32((uint32x4_t)v2));
		return (reg)vcombine_u32(res.val[0], res.val[1]);
	}

	template <>
	inline reg interleavelo<int16_t>(const reg v1, const reg v2) {
		uint16x4x2_t res = vzip_u16(vget_low_u16((uint16x8_t)v1), vget_low_u16((uint16x8_t)v2));
		return (reg)vcombine_u16(res.val[0], res.val[1]);
	}

	template <>
	inline reg interleavelo<int8_t>(const reg v1, const reg v2) {
		uint8x8x2_t res = vzip_u8(vget_low_u8((uint8x16_t)v1), vget_low_u8((uint8x16_t)v2));
		return (reg)vcombine_u8(res.val[0], res.val[1]);
	}

	// --------------------------------------------------------------------------------------------------- interleavehi
	template <>
	inline reg interleavehi<int64_t>(const reg v1, const reg v2) {
		// v1  = [a0, b0], v2 = [a1, b1]
		// res = [b0, b1]
		return (reg)vcombine_u64(vget_high_u64((uint64x2_t)v1), vget_high_u64((uint64x2_t)v2));
	}

	template <>
	inline reg interleavehi<float>(const reg v1, const reg v2) {
		// v1  = [a0, b0, c0, d0], v2 = [a1, b1, c1, d1]
		// res = [c0, c1, d0, d1]
		uint32x2x2_t res = vzip_u32(vget_high_u32((uint32x4_t)v1), vget_high_u32((uint32x4_t)v2));
		return (reg)vcombine_u32(res.val[0], res.val[1]);
	}	

	template <>
	inline reg interleavehi<int32_t>(const reg v1, const reg v2) {
		// v1  = [a0, b0, c0, d0], v2 = [a1, b1, c1, d1]
		// res = [c0, c1, d0, d1]
		uint32x2x2_t res = vzip_u32(vget_high_u32((uint32x4_t)v1), vget_high_u32((uint32x4_t)v2));
		return (reg)vcombine_u32(res.val[0], res.val[1]);
	}

	template <>
	inline reg interleavehi<int16_t>(const reg v1, const reg v2) {
		uint16x4x2_t res = vzip_u16(vget_high_u16((uint16x8_t)v1), vget_high_u16((uint16x8_t)v2));
		return (reg)vcombine_u16(res.val[0], res.val[1]);
	}

	template <>
	inline reg interleavehi<int8_t>(const reg v1, const reg v2) {
		uint8x8x2_t res = vzip_u8(vget_high_u8((uint8x16_t)v1), vget_high_u8((uint8x16_t)v2));
		return (reg)vcombine_u8(res.val[0], res.val[1]);
	}

	// ----------------------------------------------------------------------------------------------------- interleave
	template <>
	inline regx2 interleave<int64_t>(const reg v1, const reg v2) {
		// v1         = [a0, b0], v2         = [a1, b1]
		// res.val[0] = [a0, a1], res.val[1] = [b0, b1]
		regx2 res = {{(reg)vcombine_u64(vget_low_u64 ((uint64x2_t)v1), vget_low_u64 ((uint64x2_t)v2)),
		              (reg)vcombine_u64(vget_high_u64((uint64x2_t)v1), vget_high_u64((uint64x2_t)v2))}};
		return res;
	}

	template <>
	inline regx2 interleave<float>(const reg v1, const reg v2) {
		// v1         = [a0, b0, c0, d0], v2         = [a1, b1, c1, d1]
		// res.val[0] = [a0, a1, b0, b1], res.val[1] = [c0, c1, d0, d1]
		uint32x2x2_t res0 = vzip_u32(vget_low_u32 ((uint32x4_t)v1), vget_low_u32 ((uint32x4_t)v2));
		uint32x2x2_t res1 = vzip_u32(vget_high_u32((uint32x4_t)v1), vget_high_u32((uint32x4_t)v2));

		regx2 res = {{(reg)vcombine_u32(res0.val[0], res0.val[1]),
		              (reg)vcombine_u32(res1.val[0], res1.val[1])}};
		
		return res;
	}

	template <>
	inline regx2 interleave<int32_t>(const reg v1, const reg v2) {
		// v1  = [a0, b0, c0, d0], v2 = [a1, b1, c1, d1]
		// res = [a0, a1, b0, b1]
		uint32x2x2_t res0 = vzip_u32(vget_low_u32 ((uint32x4_t)v1), vget_low_u32 ((uint32x4_t)v2));
		uint32x2x2_t res1 = vzip_u32(vget_high_u32((uint32x4_t)v1), vget_high_u32((uint32x4_t)v2));

		regx2 res = {{(reg)vcombine_u32(res0.val[0], res0.val[1]),
		              (reg)vcombine_u32(res1.val[0], res1.val[1])}};
		
		return res;
	}

	template <>
	inline regx2 interleave<int16_t>(const reg v1, const reg v2) {
		uint16x4x2_t res0 = vzip_u16(vget_low_u16 ((uint16x8_t)v1), vget_low_u16 ((uint16x8_t)v2));
		uint16x4x2_t res1 = vzip_u16(vget_high_u16((uint16x8_t)v1), vget_high_u16((uint16x8_t)v2));

		regx2 res = {{(reg)vcombine_u16(res0.val[0], res0.val[1]),
		              (reg)vcombine_u16(res1.val[0], res1.val[1])}};
		
		return res;
	}

	template <>
	inline regx2 interleave<int8_t>(const reg v1, const reg v2) {
		uint8x8x2_t res0 = vzip_u8(vget_low_u8 ((uint8x16_t)v1), vget_low_u8 ((uint8x16_t)v2));
		uint8x8x2_t res1 = vzip_u8(vget_high_u8((uint8x16_t)v1), vget_high_u8((uint8x16_t)v2));

		regx2 res = {{(reg)vcombine_u8(res0.val[0], res0.val[1]),
		              (reg)vcombine_u8(res1.val[0], res1.val[1])}};
		
		return res;
	}

	// ------------------------------------------------------------------------------------------------------ transpose
	template <>
	inline void transpose<int16_t>(reg tab[nElReg<int16_t>()]) {
		// /!\ this implementation can be further improved by using the dedicated VTRN instructions.
		//
		// Transpose the 8x8 matrix:
		// -------------------------
		// tab[0] = [a0, a1, a2, a3, a4, a5, a6, a7]        tab[0] = [a0, b0, c0, d0, e0, f0, g0, h0]
		// tab[1] = [b0, b1, b2, b3, b4, b5, b6, b7]        tab[1] = [a1, b1, c1, d1, e1, f1, g1, h1]
		// tab[2] = [c0, c1, c2, c3, c4, c5, c6, c7]        tab[2] = [a2, b2, c2, d2, e2, f2, g2, h2]
		// tab[3] = [d0, d1, d2, d3, d4, d5, d6, d7]        tab[3] = [a3, b3, c3, d3, e3, f3, g3, h3]
		// tab[4] = [e0, e1, e2, e3, e4, e5, e6, e7]   =>   tab[4] = [a4, b4, c4, d4, e4, f4, g4, h4]
		// tab[5] = [f0, f1, f2, f3, f4, f5, f6, f7]        tab[5] = [a5, b5, c5, d5, e5, f5, g5, h5]
		// tab[6] = [g0, g1, g2, g3, g4, g5, g6, g7]        tab[6] = [a6, b6, c6, d6, e6, f6, g6, h6]
		// tab[7] = [h0, h1, h2, h3, h4, h5, h6, h7]        tab[7] = [a7, b7, c7, d7, e7, f7, g7, h7]

		auto ab = mipp::interleave<int16_t>(tab[0], tab[1]);
		auto cd = mipp::interleave<int16_t>(tab[2], tab[3]);
		auto ef = mipp::interleave<int16_t>(tab[4], tab[5]);
		auto gh = mipp::interleave<int16_t>(tab[6], tab[7]);

		auto a03b03 = ab.val[0];
		auto c03d03 = cd.val[0];
		auto e03f03 = ef.val[0];
		auto g03h03 = gh.val[0];
		auto a47b47 = ab.val[1];
		auto c47d47 = cd.val[1];
		auto e47f47 = ef.val[1];
		auto g47h47 = gh.val[1];

		auto a03b03c03d03 = mipp::interleave<int32_t>(a03b03, c03d03);
		auto e03f03g03h03 = mipp::interleave<int32_t>(e03f03, g03h03);
		auto a47b47c47d47 = mipp::interleave<int32_t>(a47b47, c47d47);
		auto e47f47g47h47 = mipp::interleave<int32_t>(e47f47, g47h47);

		auto a01b01c01d01 = a03b03c03d03.val[0];
		auto a23b23c23d23 = a03b03c03d03.val[1];
		auto e01f01g01h01 = e03f03g03h03.val[0];
		auto e23f23g23h23 = e03f03g03h03.val[1];
		auto a45b45c45d45 = a47b47c47d47.val[0];
		auto a67b67c67d67 = a47b47c47d47.val[1];
		auto e45f45g45h45 = e47f47g47h47.val[0];
		auto e67f67g67h67 = e47f47g47h47.val[1];

		auto a01b01c01d01e01f01g01h01 = mipp::interleave<int64_t>(a01b01c01d01, e01f01g01h01);
		auto a23b23c23d23e23f23g23h23 = mipp::interleave<int64_t>(a23b23c23d23, e23f23g23h23);
		auto a45b45c45d45e45f45g45h45 = mipp::interleave<int64_t>(a45b45c45d45, e45f45g45h45);
		auto a67b67c67d67e67f67g67h67 = mipp::interleave<int64_t>(a67b67c67d67, e67f67g67h67);

		auto a0b0c0d0e0f0g0h0 = a01b01c01d01e01f01g01h01.val[0];
		auto a1b1c1d1e1f1g1h1 = a01b01c01d01e01f01g01h01.val[1];
		auto a2b2c2d2e2f2g2h2 = a23b23c23d23e23f23g23h23.val[0];
		auto a3b3c3d3e3f3g3h3 = a23b23c23d23e23f23g23h23.val[1];
		auto a4b4c4d4e4f4g4h4 = a45b45c45d45e45f45g45h45.val[0];
		auto a5b5c5d5e5f5g5h5 = a45b45c45d45e45f45g45h45.val[1];
		auto a6b6c6d6e6f6g6h6 = a67b67c67d67e67f67g67h67.val[0];
		auto a7b7c7d7e7f7g7h7 = a67b67c67d67e67f67g67h67.val[1];

		tab[0] = (reg)a0b0c0d0e0f0g0h0;
		tab[1] = (reg)a1b1c1d1e1f1g1h1;
		tab[2] = (reg)a2b2c2d2e2f2g2h2;
		tab[3] = (reg)a3b3c3d3e3f3g3h3;
		tab[4] = (reg)a4b4c4d4e4f4g4h4;
		tab[5] = (reg)a5b5c5d5e5f5g5h5;
		tab[6] = (reg)a6b6c6d6e6f6g6h6;
		tab[7] = (reg)a7b7c7d7e7f7g7h7;
	}

	// --------------------------------------------------------------------------------------------------- transpose8x8
	template <>
	inline void transpose8x8<int8_t>(reg tab[8]) {
		mipp::transpose<int16_t>(tab);
	}

	// ----------------------------------------------------------------------------------------------------------- andb
	template <>
	inline reg andb<float>(const reg v1, const reg v2) {
		return (reg) vandq_u32((uint32x4_t) v1, (uint32x4_t) v2);
	}

	template <>
	inline reg andb<int32_t>(const reg v1, const reg v2) {
		return (reg) vandq_u32((uint32x4_t) v1, (uint32x4_t) v2);
	}

	template <>
	inline reg andb<int16_t>(const reg v1, const reg v2) {
		return (reg) vandq_u16((uint16x8_t) v1, (uint16x8_t) v2);
	}

	template <>
	inline reg andb<int8_t>(const reg v1, const reg v2) {
		return (reg) vandq_u8((uint8x16_t) v1, (uint8x16_t) v2);
	}

	// ----------------------------------------------------------------------------------------------------------- notb

	template <>
	inline reg notb<float>(const reg v) {
		return (reg) vmvnq_u32((uint32x4_t) v);
	}

	template <>
	inline reg notb<int32_t>(const reg v) {
		return (reg) vmvnq_u32((uint32x4_t) v);
	}

	template <>
	inline reg notb<int16_t>(const reg v) {
		return (reg) vmvnq_u16((uint16x8_t) v);
	}

	template <>
	inline reg notb<int8_t>(const reg v) {
		return (reg) vmvnq_u8((uint8x16_t) v);
	}

	// ---------------------------------------------------------------------------------------------------------- andnb
	template <>
	inline reg andnb<float>(const reg v1, const reg v2) {
		return (reg) vandq_u32(vmvnq_u32((uint32x4_t) v1), (uint32x4_t) v2);
	}

	template <>
	inline reg andnb<int32_t>(const reg v1, const reg v2) {
		return (reg) vandq_u32(vmvnq_u32((uint32x4_t) v1), (uint32x4_t) v2);
	}

	template <>
	inline reg andnb<int16_t>(const reg v1, const reg v2) {
		return (reg) vandq_u16(vmvnq_u16((uint16x8_t) v1), (uint16x8_t) v2);
	}

	template <>
	inline reg andnb<int8_t>(const reg v1, const reg v2) {
		return (reg) vandq_u8(vmvnq_u8((uint8x16_t) v1), (uint8x16_t) v2);
	}

	// ------------------------------------------------------------------------------------------------------------ orb
	template <>
	inline reg orb<float>(const reg v1, const reg v2) {
		return (reg) vorrq_u32((uint32x4_t) v1, (uint32x4_t) v2);
	}

	template <>
	inline reg orb<int32_t>(const reg v1, const reg v2) {
		return (reg) vorrq_s32((int32x4_t) v1, (int32x4_t) v2);
	}

	template <>
	inline reg orb<int16_t>(const reg v1, const reg v2) {
		return (reg) vorrq_s16((int16x8_t) v1, (int16x8_t) v2);
	}

	template <>
	inline reg orb<int8_t>(const reg v1, const reg v2) {
		return (reg) vorrq_s8((int8x16_t) v1, (int8x16_t) v2);
	}

	// ----------------------------------------------------------------------------------------------------------- xorb
	template <>
	inline reg xorb<float>(const reg v1, const reg v2) {
		return (reg) veorq_u32((uint32x4_t) v1, (uint32x4_t) v2);
	}

	template <>
	inline reg xorb<int32_t>(const reg v1, const reg v2) {
		return (reg) veorq_s32((int32x4_t) v1, (int32x4_t) v2);
	}

	template <>
	inline reg xorb<int16_t>(const reg v1, const reg v2) {
		return (reg) veorq_s16((int16x8_t) v1, (int16x8_t) v2);
	}

	template <>
	inline reg xorb<int8_t>(const reg v1, const reg v2) {
		return (reg) veorq_s8((int8x16_t) v1, (int8x16_t) v2);
	}

	// --------------------------------------------------------------------------------------------------------- lshift
	template <>
	inline reg lshift<int32_t>(const reg v1, const uint32_t n) {
		return (reg) vshlq_u32((uint32x4_t) v1, (int32x4_t)mipp::set1<int32_t>(n));
	}

	template <>
	inline reg lshift<int16_t>(const reg v1, const uint32_t n) {
		return (reg) vshlq_u16((uint16x8_t) v1, (int16x8_t)mipp::set1<int16_t>((int16_t) n));
	}

	template <>
	inline reg lshift<int8_t>(const reg v1, const uint32_t n) {
		return (reg) vshlq_u8((uint8x16_t) v1, (int8x16_t)mipp::set1<int8_t>((int8_t) n));
	}

	// --------------------------------------------------------------------------------------------------------- rshift
	template <>
	inline reg rshift<int32_t>(const reg v1, const uint32_t n) {
		return (reg) vshlq_u32((uint32x4_t) v1, (int32x4_t)mipp::set1<int32_t>(-n));
	}

	template <>
	inline reg rshift<int16_t>(const reg v1, const uint32_t n) {
		return (reg) vshlq_u16((uint16x8_t) v1, (int16x8_t)mipp::set1<int16_t>((int16_t)-n));
	}

	template <>
	inline reg rshift<int8_t>(const reg v1, const uint32_t n) {
		return (reg) vshlq_u8((uint8x16_t) v1, (int8x16_t)mipp::set1<int8_t>((int8_t)-n));
	}

	// ---------------------------------------------------------------------------------------------------------- cmpeq
	template <>
	inline reg cmpeq<float>(const reg v1, const reg v2) {
		return (reg) vceqq_f32(v1, v2);
	}

	template <>
	inline reg cmpeq<int32_t>(const reg v1, const reg v2) {
		return (reg) vceqq_s32((int32x4_t) v1, (int32x4_t) v2);
	}

	template <>
	inline reg cmpeq<int16_t>(const reg v1, const reg v2) {
		return (reg) vceqq_s16((int16x8_t) v1, (int16x8_t) v2);
	}

	template <>
	inline reg cmpeq<int8_t>(const reg v1, const reg v2) {
		return (reg) vceqq_s8((int8x16_t) v1, (int8x16_t) v2);
	}

	// --------------------------------------------------------------------------------------------------------- cmpneq
	template <>
	inline reg cmpneq<float>(const reg v1, const reg v2) {
		return (reg) vmvnq_u32((uint32x4_t) vceqq_f32(v1, v2));
	}

	template <>
	inline reg cmpneq<int32_t>(const reg v1, const reg v2) {
		return (reg) vmvnq_u32((uint32x4_t) vceqq_s32((int32x4_t) v1, (int32x4_t) v2));
	}

	template <>
	inline reg cmpneq<int16_t>(const reg v1, const reg v2) {
		return (reg) vmvnq_u16((uint16x8_t) vceqq_s16((int16x8_t) v1, (int16x8_t) v2));
	}

	template <>
	inline reg cmpneq<int8_t>(const reg v1, const reg v2) {
		return (reg) vmvnq_u8((uint8x16_t) vceqq_s8((int8x16_t) v1, (int8x16_t) v2));
	}

	// ---------------------------------------------------------------------------------------------------------- cmplt
	template <>
	inline reg cmplt<float>(const reg v1, const reg v2) {
		return (reg) vcltq_f32(v1, v2);
	}

	template <>
	inline reg cmplt<int32_t>(const reg v1, const reg v2) {
		return (reg) vcltq_s32((int32x4_t) v1, (int32x4_t) v2);
	}

	template <>
	inline reg cmplt<int16_t>(const reg v1, const reg v2) {
		return (reg) vcltq_s16((int16x8_t) v1, (int16x8_t) v2);
	}

	template <>
	inline reg cmplt<int8_t>(const reg v1, const reg v2) {
		return (reg) vcltq_s8((int8x16_t) v1, (int8x16_t) v2);
	}

	// ---------------------------------------------------------------------------------------------------------- cmple
	template <>
	inline reg cmple<float>(const reg v1, const reg v2) {
		return (reg) vcleq_f32(v1, v2);
	}

	template <>
	inline reg cmple<int32_t>(const reg v1, const reg v2) {
		return (reg) vcleq_s32((int32x4_t) v1, (int32x4_t) v2);
	}

	template <>
	inline reg cmple<int16_t>(const reg v1, const reg v2) {
		return (reg) vcleq_s16((int16x8_t) v1, (int16x8_t) v2);
	}

	template <>
	inline reg cmple<int8_t>(const reg v1, const reg v2) {
		return (reg) vcleq_s8((int8x16_t) v1, (int8x16_t) v2);
	}

	// ---------------------------------------------------------------------------------------------------------- cmpgt
	template <>
	inline reg cmpgt<float>(const reg v1, const reg v2) {
		return (reg) vcgtq_f32(v1, v2);
	}

	template <>
	inline reg cmpgt<int32_t>(const reg v1, const reg v2) {
		return (reg) vcgtq_s32((int32x4_t) v1, (int32x4_t) v2);
	}

	template <>
	inline reg cmpgt<int16_t>(const reg v1, const reg v2) {
		return (reg) vcgtq_s16((int16x8_t) v1, (int16x8_t) v2);
	}

	template <>
	inline reg cmpgt<int8_t>(const reg v1, const reg v2) {
		return (reg) vcgtq_s8((int8x16_t) v1, (int8x16_t) v2);
	}
	
	// ---------------------------------------------------------------------------------------------------------- cmpge
	template <>
	inline reg cmpge<float>(const reg v1, const reg v2) {
		return (reg) vcgeq_f32(v1, v2);
	}

	template <>
	inline reg cmpge<int32_t>(const reg v1, const reg v2) {
		return (reg) vcgeq_s32((int32x4_t) v1, (int32x4_t) v2);
	}

	template <>
	inline reg cmpge<int16_t>(const reg v1, const reg v2) {
		return (reg) vcgeq_s16((int16x8_t) v1, (int16x8_t) v2);
	}

	template <>
	inline reg cmpge<int8_t>(const reg v1, const reg v2) {
		return (reg) vcgeq_s8((int8x16_t) v1, (int8x16_t) v2);
	}

	// ------------------------------------------------------------------------------------------------------------ add
	template <>
	inline reg add<float>(const reg v1, const reg v2) {
		return vaddq_f32(v1, v2);
	}

	template <>
	inline reg add<int32_t>(const reg v1, const reg v2) {
		return (reg) vaddq_s32((int32x4_t) v1, (int32x4_t)v2);
	}

	template <>
	inline reg add<int16_t>(const reg v1, const reg v2) {
		return (reg) vqaddq_s16((int16x8_t) v1, (int16x8_t)v2);
	}

	template <>
	inline reg add<int8_t>(const reg v1, const reg v2) {
		return (reg) vqaddq_s8((int8x16_t) v1, (int8x16_t)v2);
	}

	// ------------------------------------------------------------------------------------------------------------ sub
	template <>
	inline reg sub<float>(const reg v1, const reg v2) {
		return vsubq_f32(v1, v2);
	}

	template <>
	inline reg sub<int32_t>(const reg v1, const reg v2) {
		return (reg) vsubq_s32((int32x4_t) v1, (int32x4_t) v2);
	}

	template <>
	inline reg sub<int16_t>(const reg v1, const reg v2) {
		return (reg) vqsubq_s16((int16x8_t) v1, (int16x8_t) v2);
	}

	template <>
	inline reg sub<int8_t>(const reg v1, const reg v2) {
		return (reg) vqsubq_s8((int8x16_t) v1, (int8x16_t) v2);
	}

	// ------------------------------------------------------------------------------------------------------------ mul
	template <>
	inline reg mul<float>(const reg v1, const reg v2) {
		return vmulq_f32(v1, v2);
	}

	template <>
	inline reg mul<int32_t>(const reg v1, const reg v2) {
		return (reg) vmulq_s32((int32x4_t) v1, (int32x4_t) v2);
	}

	// ------------------------------------------------------------------------------------------------------------ div
	template <>
	inline reg div<float>(const reg v1, const reg v2) {
		return mul<float>(v1, vrecpeq_f32(v2));
	}

	// ------------------------------------------------------------------------------------------------------------ min
	template <>
	inline reg min<float>(const reg v1, const reg v2) {
		return vminq_f32(v1, v2);
	}

	template <>
	inline reg min<int32_t>(const reg v1, const reg v2) {
		return (reg) vminq_s32((int32x4_t) v1, (int32x4_t) v2);
	}

	template <>
	inline reg min<int16_t>(const reg v1, const reg v2) {
		return (reg) vminq_s16((int16x8_t) v1, (int16x8_t) v2);
	}

	template <>
	inline reg min<int8_t>(const reg v1, const reg v2) {
		return (reg) vminq_s8((int8x16_t) v1, (int8x16_t) v2);
	}

	// ------------------------------------------------------------------------------------------------------------ max
	template <>
	inline reg max<float>(const reg v1, const reg v2) {
		return vmaxq_f32(v1, v2);
	}

	template <>
	inline reg max<int32_t>(const reg v1, const reg v2) {
		return (reg) vmaxq_s32((int32x4_t) v1, (int32x4_t) v2);
	}

	template <>
	inline reg max<int16_t>(const reg v1, const reg v2) {
		return (reg) vmaxq_s16((int16x8_t) v1, (int16x8_t) v2);
	}

	template <>
	inline reg max<int8_t>(const reg v1, const reg v2) {
		return (reg) vmaxq_s8((int8x16_t) v1, (int8x16_t) v2);
	}

	// ----------------------------------------------------------------------------------------------------------- sign
	template <>
	inline reg sign<float>(const reg v1) {
		// sign_mask = 10000000000000000000000000000000 // 32 bits
		const reg sign_mask = set1<int32_t>(0x80000000);

		// indices   = 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
		// sign_mask =  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
		// v1        =  ù  €  è  é  à  &  z  y  x  w  v  u  t  s  r  q  p  o  n  m  l  k  j  i  h  g  f  e  d  c  b  a
		// res       =  ù  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
		// res is the sign because the first bit is the sign bit (0 = positive, 1 = negative)
		return andb<float>(v1, sign_mask);
	}

	template <>
	inline reg sign<float>(const reg v1, const reg v2) {
		reg sign_v1_v2 = xorb<float>(v1, v2);
		    sign_v1_v2 = sign<float>(sign_v1_v2);
		return sign_v1_v2;
	}

	template <>
	inline reg sign<int16_t>(const reg v1) {
		const reg sign_mask = set1<int16_t>(0x8000);
		return andb<int16_t>(v1, sign_mask);
	}

	template <>
	inline reg sign<int16_t>(const reg v1, const reg v2) {
		reg sign_v1_v2 = xorb<int16_t>(v1, v2);
		    sign_v1_v2 = sign<int16_t>(sign_v1_v2);
		return sign_v1_v2;
	}

	template <>
	inline reg sign<int8_t>(const reg v1) {
		const reg sign_mask = set1<int8_t>(0x80);
		return andb<int8_t>(v1, sign_mask);
	}

	template <>
	inline reg sign<int8_t>(const reg v1, const reg v2) {
		reg sign_v1_v2 = xorb<int8_t>(v1, v2);
		    sign_v1_v2 = sign<int8_t>(sign_v1_v2);
		return sign_v1_v2;
	}

	// ------------------------------------------------------------------------------------------------------------ neg
	template <>
	inline reg neg<float>(const reg v1, const reg v2) {
		return xorb<float>(v1, v2);
	}

	template <>
	inline reg neg<int16_t>(const reg v1, const reg v2) {
		reg neg_v1 = (reg) vqnegq_s16((int16x8_t) v1);
		reg v2_2   = orb  <int16_t>(v2, set1<int16_t>(1)); // hack to avoid -0 case
		reg mask   = cmplt<int16_t>(v2_2, set0<int16_t>());
		reg res1   = andb <int16_t>(mask, neg_v1);
		reg res2   = andb <int16_t>((reg) vmvnq_s16((int16x8_t) mask), v1);
		reg res    = orb  <int16_t>(res1, res2);
		return res;
	}

	template <>
	inline reg neg<int8_t>(const reg v1, const reg v2) {
		reg neg_v1 = (reg) vqnegq_s8((int8x16_t) v1);
		reg v2_2   = orb  <int8_t>(v2, set1<int8_t>(1)); // hack to avoid -0 case
		reg mask   = cmplt<int8_t>(v2_2, set0<int8_t>());
		reg res1   = andb <int8_t>(mask, neg_v1);
		reg res2   = andb <int8_t>((reg) vmvnq_s8((int8x16_t) mask), v1);
		reg res    = orb  <int8_t>(res1, res2);
		return res;
	}

	// ------------------------------------------------------------------------------------------------------------ neg
	template <>
	inline reg neg<float>(const reg v) {
		return xorb<int32_t>(v, mipp::set1<int32_t>(0x80000000));
	}

	template <>
	inline reg neg<int32_t>(const reg v) {
		return (reg) vqnegq_s32((int32x4_t) v);
	}

	template <>
	inline reg neg<int16_t>(const reg v) {
		return (reg) vqnegq_s16((int16x8_t) v);
	}

	template <>
	inline reg neg<int8_t>(const reg v) {
		return (reg) vqnegq_s8((int8x16_t) v);
	}

	// ------------------------------------------------------------------------------------------------------------ abs
	template <>
	inline reg abs<float>(const reg v1) {
		return vabsq_f32(v1);
	}

	template <>
	inline reg abs<int16_t>(const reg v1) {
		return (reg) vabsq_s16((int16x8_t)v1);
	}

	template <>
	inline reg abs<int8_t>(const reg v1) {
		return (reg) vabsq_s8((int8x16_t)v1);
	}

	// ---------------------------------------------------------------------------------------------------------- rsqrt
	template <>
	inline reg rsqrt<float>(const reg v1) {
		return vrsqrteq_f32(v1);
	}

	// ------------------------------------------------------------------------------------------------------------ log
	template <>
	inline reg log<float>(const reg v) {
		auto v_bis = v;
		return (reg) log_ps(v_bis);
	}

	// ------------------------------------------------------------------------------------------------------------ exp
	template <>
	inline reg exp<float>(const reg v) {
		auto v_bis = v;
		return (reg) exp_ps(v_bis);
	}

	// ------------------------------------------------------------------------------------------------------------ sin
	template <>
	inline reg sin<float>(const reg v) {
		auto v_bis = v;
		return (reg) sin_ps(v_bis);
	}

	// ------------------------------------------------------------------------------------------------------------ cos
	template <>
	inline reg cos<float>(const reg v) {
		auto v_bis = v;
		return (reg) cos_ps(v_bis);
	}

	// --------------------------------------------------------------------------------------------------------- sincos
	template <>
	inline void sincos<float>(const reg x, reg &s, reg &c) {
		sincos_ps(x, &s, &c);
	}

	// ----------------------------------------------------------------------------------------------------------- sqrt
	template <>
	inline reg sqrt<float>(const reg v1) {
		return vrecpeq_f32(rsqrt<float>(v1));
	}

	// ---------------------------------------------------------------------------------------------------------- fmadd
	template <>
	inline reg fmadd<float>(const reg v1, const reg v2, const reg v3) {
		return add<float>(v3, mul<float>(v1, v2));
	}

	// --------------------------------------------------------------------------------------------------------- fnmadd
	template <>
	inline reg fnmadd<float>(const reg v1, const reg v2, const reg v3) {
		return sub<float>(v3, mul<float>(v1, v2));
	}


	// ---------------------------------------------------------------------------------------------------------- fmsub
	template <>
	inline reg fmsub<float>(const reg v1, const reg v2, const reg v3) {
		return sub<float>(mul<float>(v1, v2), v3);
	}

	// ---------------------------------------------------------------------------------------------------------- blend
	template <>
	inline reg blend<float>(const reg v1, const reg v2, const reg m) {
		return (float32x4_t)vbslq_f32((uint32x4_t)m, (float32x4_t)v1, (float32x4_t)v2);
	}

	template <>
	inline reg blend<int32_t>(const reg v1, const reg v2, const reg m) {
		return (float32x4_t)vbslq_u32((uint32x4_t)m, (uint32x4_t)v1, (uint32x4_t)v2);
	}

	template <>
	inline reg blend<int16_t>(const reg v1, const reg v2, const reg m) {
		return (float32x4_t)vbslq_u16((uint16x8_t)m, (uint16x8_t)v1, (uint16x8_t)v2);
	}

	template <>
	inline reg blend<int8_t>(const reg v1, const reg v2, const reg m) {
		return (float32x4_t)vbslq_u8((uint8x16_t)m, (uint8x16_t)v1, (uint8x16_t)v2);
	}

	// ------------------------------------------------------------------------------------------------------------ rot
	template <>
	inline reg rot<float>(const reg v1) {
		// make a rotation in:[3, 2 , 1, 0] => out:[2, 1, 0, 3]
		return vextq_f32(v1, v1, 3);
	}

	template <>
	inline reg rot<int16_t>(const reg v1) {
		// make a rotation in:[7, 6, 5, 4, 3, 2 , 1, 0] => out:[6, 5, 4, 3, 3, 1, 0, 7]
		return (reg)vextq_u16((uint16x8_t)v1, (uint16x8_t)v1, 7);
	}

	// ----------------------------------------------------------------------------------------------------------- rotr
	template <>
	inline reg rotr<float>(const reg v1) {
		// make a rotation in:[3, 2 , 1, 0] => out:[0, 3, 2, 1]
		return vextq_f32(v1, v1, 1);
	}

	template <>
	inline reg rotr<int16_t>(const reg v1) {
		// make a rotation in:[7, 6, 5, 4, 3, 2 , 1, 0] => out:[0, 7, 6, 5, 4, 3, 2, 1]
		return (reg)vextq_u16((uint16x8_t)v1, (uint16x8_t)v1, 1);
	}

	// ----------------------------------------------------------------------------------------------------------- div2
	template <>
	inline reg div2<float>(const reg v1) {
		return mul<float>(v1, set1<float>(0.5f));
	}

	template <>
	inline reg div2<int32_t>(const reg v1) {
		reg abs_v1 = abs<int32_t>(v1);
		reg sh = rshift<int32_t>(abs_v1, 1);
		return neg<int32_t>(sh, v1);
	}

	template <>
	inline reg div2<int16_t>(const reg v1) {
		reg abs_v1 = abs<int16_t>(v1);
		reg sh = rshift<int16_t>(abs_v1, 1);
		return neg<int16_t>(sh, v1);
	}

	template <>
	inline reg div2<int8_t>(const reg v1) {
		reg abs_v1 = abs<int8_t>(v1);
		reg sh = rshift<int8_t>(abs_v1, 1);
		return neg<int8_t>(sh, v1);
	}

	// ----------------------------------------------------------------------------------------------------------- div4
	template <>
	inline reg div4<float>(const reg v1) {
		return mul<float>(v1, set1<float>(0.25f));
	}

	template <>
	inline reg div4<int32_t>(const reg v1) {
		reg abs_v1 = abs<int32_t>(v1);
		reg sh = rshift<int32_t>(abs_v1, 2);
		return neg<int32_t>(sh, v1);
	}    

	template <>
	inline reg div4<int16_t>(const reg v1) {
		reg abs_v1 = abs<int16_t>(v1);
		reg sh = rshift<int16_t>(abs_v1, 2);
		return neg<int16_t>(sh, v1);
	}    

	template <>
	inline reg div4<int8_t>(const reg v1) {
		reg abs_v1 = abs<int8_t>(v1);
		reg sh = rshift<int8_t>(abs_v1, 2);
		return neg<int8_t>(sh, v1);
	}

	// ------------------------------------------------------------------------------------------------------------ sat
	template <>
	inline reg sat<float>(const reg v1, float min, float max) {
		return mipp::min<float>(mipp::max<float>(v1, set1<float>(min)), set1<float>(max));
	}

	template <>
	inline reg sat<double>(const reg v1, double min, double max) {
		return mipp::min<double>(mipp::max<double>(v1, set1<double>(min)), set1<double>(max));
	}

	template <>
	inline reg sat<int32_t>(const reg v1, int32_t min, int32_t max) {
		return mipp::min<int32_t>(mipp::max<int32_t>(v1, set1<int32_t>(min)), set1<int32_t>(max));
	}

	template <>
	inline reg sat<int16_t>(const reg v1, int16_t min, int16_t max) {
		return mipp::min<int16_t>(mipp::max<int16_t>(v1, set1<int16_t>(min)), set1<int16_t>(max));
	}

	template <>
	inline reg sat<int8_t>(const reg v1, int8_t min, int8_t max) {
		return mipp::min<int8_t>(mipp::max<int8_t>(v1, set1<int8_t>(min)), set1<int8_t>(max));
	}

	// ------------------------------------------------------------------------------------------------------------ cvt
	template <>
	inline reg cvt<float,int32_t>(const reg v) {
		return (reg) vcvtq_s32_f32((float32x4_t) v);
	}

	template <>
	inline reg cvt<int32_t,float>(const reg v) {
		return (reg) vcvtq_f32_s32((int32x4_t) v);
	}

	template <>
	inline reg cvt<int8_t,int16_t>(const reg_2 v) {
		return (reg) vmovl_s8((int8x8_t) v);
	}

	template <>
	inline reg cvt<int16_t,int32_t>(const reg_2 v) {
		return (reg) vmovl_s16((int16x4_t) v);
	}

	// ---------------------------------------------------------------------------------------------------------- round
	template <>
	inline reg round<float>(const reg v) {
		auto half = mipp::orb<float>(mipp::sign<float>(v), mipp::set1<float>(0.5f));
		auto tmp = mipp::add<float>(v, half);
		return mipp::cvt<int32_t,float>(mipp::cvt<float,int32_t>(tmp));
	}

	// ----------------------------------------------------------------------------------------------------------- pack
	template <>
	inline reg pack<int32_t,int16_t>(const reg v1, const reg v2) {
		return (reg) vcombine_s16(vqmovn_s32((int32x4_t) v1), vqmovn_s32((int32x4_t) v2));
	}

	template <>
	inline reg pack<int16_t,int8_t>(const reg v1, const reg v2) {
		return (reg) vcombine_s8(vqmovn_s16((int16x8_t) v1), vqmovn_s16((int16x8_t) v2));
	}

	// ------------------------------------------------------------------------------------------------------ reduction
	template <red_op<float> OP>
	struct _reduction<float,OP>
	{
		static reg apply(const reg v1) {
			auto val = v1;

			val = OP(val, (reg) vextq_f32(val, val, 2));

			float32x2_t low1  = vrev64_f32(vget_low_f32 (val));
			float32x2_t high1 = vrev64_f32(vget_high_f32(val));
			val = OP(val, vcombine_f32(low1, high1));

			return val;
		}
	};

	template <Red_op<float> OP>
	struct _Reduction<float,OP>
	{
		static Reg<float> apply(const Reg<float> v1) {
			auto val = v1;

			val = OP(val, Reg<float>((reg) vextq_f32(val.r, val.r, 2)));

			float32x2_t low1  = vrev64_f32(vget_low_f32 (val.r));
			float32x2_t high1 = vrev64_f32(vget_high_f32(val.r));
			val = OP(val, Reg<float>(vcombine_f32(low1, high1)));

			return val;
		}
	};

	template <red_op<int32_t> OP>
	struct _reduction<int32_t,OP>
	{
		static reg apply(const reg v1) {
			auto val = v1;

			val = OP(val, (reg) vextq_s32((int32x4_t) val, (int32x4_t) val, 2));

			int32x2_t low1  = vrev64_s32((int32x2_t) vget_low_s32 ((int32x4_t) val));
			int32x2_t high1 = vrev64_s32((int32x2_t) vget_high_s32((int32x4_t) val));
			val = OP(val, (reg) vcombine_s32((int32x2_t) low1, (int32x2_t) high1));

			return val;
		}
	};

	template <Red_op<int32_t> OP>
	struct _Reduction<int32_t,OP>
	{
		static Reg<int32_t> apply(const Reg<int32_t> v1) {
			auto val = v1;

			val = OP(val, Reg<int32_t>((reg) vextq_s32((int32x4_t) val.r, (int32x4_t) val.r, 2)));

			int32x2_t low1  = vrev64_s32((int32x2_t) vget_low_s32 ((int32x4_t) val.r));
			int32x2_t high1 = vrev64_s32((int32x2_t) vget_high_s32((int32x4_t) val.r));
			val = OP(val, Reg<int32_t>((reg) vcombine_s32((int32x2_t) low1, (int32x2_t) high1)));

			return val;
		}
	};

	template <red_op<int16_t> OP>
	struct _reduction<int16_t,OP>
	{
		static reg apply(const reg v1) {
			auto val = v1;

			val = OP(val, (reg) vextq_s32((int32x4_t) val, (int32x4_t) val, 2));

			int32x2_t low1  = vrev64_s32((int32x2_t) vget_low_s32 ((int32x4_t) val));
			int32x2_t high1 = vrev64_s32((int32x2_t) vget_high_s32((int32x4_t) val));
			val = OP(val, (reg) vcombine_s32((int32x2_t) low1, (int32x2_t) high1));

			int16x4_t low2  = vrev32_s16((int16x4_t) vget_low_s32((int32x4_t) val));
			int16x4_t high2 = vrev32_s16((int16x4_t) vget_high_s32((int32x4_t) val));
			val = OP(val, (reg) vcombine_s32((int32x2_t) low2, (int32x2_t) high2));

			return val;
		}
	};

	template <Red_op<int16_t> OP>
	struct _Reduction<int16_t,OP>
	{
		static Reg<int16_t> apply(const Reg<int16_t> v1) {
			auto val = v1;

			val = OP(val, Reg<int16_t>((reg) vextq_s32((int32x4_t) val.r, (int32x4_t) val.r, 2)));

			int32x2_t low1  = vrev64_s32((int32x2_t) vget_low_s32 ((int32x4_t) val.r));
			int32x2_t high1 = vrev64_s32((int32x2_t) vget_high_s32((int32x4_t) val.r));
			val = OP(val, Reg<int16_t>((reg) vcombine_s32((int32x2_t) low1, (int32x2_t) high1)));

			int16x4_t low2  = vrev32_s16((int16x4_t) vget_low_s32((int32x4_t) val.r));
			int16x4_t high2 = vrev32_s16((int16x4_t) vget_high_s32((int32x4_t) val.r));
			val = OP(val, Reg<int16_t>((reg) vcombine_s32((int32x2_t) low2, (int32x2_t) high2)));

			return val;
		}
	};

	template <red_op<int8_t> OP>
	struct _reduction<int8_t,OP>
	{
		static reg apply(const reg v1) {
			auto val = v1;

			val = OP(val, (reg) vextq_s32((int32x4_t) val, (int32x4_t) val, 2));

			int32x2_t low1  = vrev64_s32((int32x2_t) vget_low_s32 ((int32x4_t) val));
			int32x2_t high1 = vrev64_s32((int32x2_t) vget_high_s32((int32x4_t) val));
			val = OP(val, (reg) vcombine_s32((int32x2_t) low1, (int32x2_t) high1));

			int16x4_t low2  = vrev32_s16((int16x4_t) vget_low_s32((int32x4_t) val));
			int16x4_t high2 = vrev32_s16((int16x4_t) vget_high_s32((int32x4_t) val));
			val = OP(val, (reg) vcombine_s32((int32x2_t) low2, (int32x2_t) high2));

			int8x8_t low3  = vrev16_s8((int8x8_t) vget_low_s32((int32x4_t) val));
			int8x8_t high3 = vrev16_s8((int8x8_t) vget_high_s32((int32x4_t) val));
			val = OP(val, (reg) vcombine_s32((int32x2_t) low3, (int32x2_t) high3));

			return val;
		}
	};

	template <Red_op<int8_t> OP>
	struct _Reduction<int8_t,OP>
	{
		static Reg<int8_t> apply(const Reg<int8_t> v1) {
			auto val = v1;

			val = OP(val, Reg<int8_t>((reg) vextq_s32((int32x4_t) val.r, (int32x4_t) val.r, 2)));

			int32x2_t low1  = vrev64_s32((int32x2_t) vget_low_s32 ((int32x4_t) val.r));
			int32x2_t high1 = vrev64_s32((int32x2_t) vget_high_s32((int32x4_t) val.r));
			val = OP(val, Reg<int8_t>((reg) vcombine_s32((int32x2_t) low1, (int32x2_t) high1)));

			int16x4_t low2  = vrev32_s16((int16x4_t) vget_low_s32((int32x4_t) val.r));
			int16x4_t high2 = vrev32_s16((int16x4_t) vget_high_s32((int32x4_t) val.r));
			val = OP(val, Reg<int8_t>((reg) vcombine_s32((int32x2_t) low2, (int32x2_t) high2)));

			int8x8_t low3  = vrev16_s8((int8x8_t) vget_low_s32((int32x4_t) val.r));
			int8x8_t high3 = vrev16_s8((int8x8_t) vget_high_s32((int32x4_t) val.r));
			val = OP(val, Reg<int8_t>((reg) vcombine_s32((int32x2_t) low3, (int32x2_t) high3)));

			return val;
		}
	};
#endif