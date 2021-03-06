// SPDX-License-Identifier: Apache-2.0 OR MIT OR Unlicense

// Code auto-generated by piet-gpu-derive

struct AnnoFillRef {
    uint offset;
};

struct AnnoStrokeRef {
    uint offset;
};

struct AnnoClipRef {
    uint offset;
};

struct AnnotatedRef {
    uint offset;
};

struct AnnoFill {
    vec4 bbox;
    uint rgba_color;
};

#define AnnoFill_size 20

AnnoFillRef AnnoFill_index(AnnoFillRef ref, uint index) {
    return AnnoFillRef(ref.offset + index * AnnoFill_size);
}

struct AnnoStroke {
    vec4 bbox;
    uint rgba_color;
    float linewidth;
};

#define AnnoStroke_size 24

AnnoStrokeRef AnnoStroke_index(AnnoStrokeRef ref, uint index) {
    return AnnoStrokeRef(ref.offset + index * AnnoStroke_size);
}

struct AnnoClip {
    vec4 bbox;
};

#define AnnoClip_size 16

AnnoClipRef AnnoClip_index(AnnoClipRef ref, uint index) {
    return AnnoClipRef(ref.offset + index * AnnoClip_size);
}

#define Annotated_Nop 0
#define Annotated_Stroke 1
#define Annotated_Fill 2
#define Annotated_BeginClip 3
#define Annotated_EndClip 4
#define Annotated_size 28

AnnotatedRef Annotated_index(AnnotatedRef ref, uint index) {
    return AnnotatedRef(ref.offset + index * Annotated_size);
}

AnnoFill AnnoFill_read(AnnoFillRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = annotated[ix + 0];
    uint raw1 = annotated[ix + 1];
    uint raw2 = annotated[ix + 2];
    uint raw3 = annotated[ix + 3];
    uint raw4 = annotated[ix + 4];
    AnnoFill s;
    s.bbox = vec4(uintBitsToFloat(raw0), uintBitsToFloat(raw1), uintBitsToFloat(raw2), uintBitsToFloat(raw3));
    s.rgba_color = raw4;
    return s;
}

void AnnoFill_write(AnnoFillRef ref, AnnoFill s) {
    uint ix = ref.offset >> 2;
    annotated[ix + 0] = floatBitsToUint(s.bbox.x);
    annotated[ix + 1] = floatBitsToUint(s.bbox.y);
    annotated[ix + 2] = floatBitsToUint(s.bbox.z);
    annotated[ix + 3] = floatBitsToUint(s.bbox.w);
    annotated[ix + 4] = s.rgba_color;
}

AnnoStroke AnnoStroke_read(AnnoStrokeRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = annotated[ix + 0];
    uint raw1 = annotated[ix + 1];
    uint raw2 = annotated[ix + 2];
    uint raw3 = annotated[ix + 3];
    uint raw4 = annotated[ix + 4];
    uint raw5 = annotated[ix + 5];
    AnnoStroke s;
    s.bbox = vec4(uintBitsToFloat(raw0), uintBitsToFloat(raw1), uintBitsToFloat(raw2), uintBitsToFloat(raw3));
    s.rgba_color = raw4;
    s.linewidth = uintBitsToFloat(raw5);
    return s;
}

void AnnoStroke_write(AnnoStrokeRef ref, AnnoStroke s) {
    uint ix = ref.offset >> 2;
    annotated[ix + 0] = floatBitsToUint(s.bbox.x);
    annotated[ix + 1] = floatBitsToUint(s.bbox.y);
    annotated[ix + 2] = floatBitsToUint(s.bbox.z);
    annotated[ix + 3] = floatBitsToUint(s.bbox.w);
    annotated[ix + 4] = s.rgba_color;
    annotated[ix + 5] = floatBitsToUint(s.linewidth);
}

AnnoClip AnnoClip_read(AnnoClipRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = annotated[ix + 0];
    uint raw1 = annotated[ix + 1];
    uint raw2 = annotated[ix + 2];
    uint raw3 = annotated[ix + 3];
    AnnoClip s;
    s.bbox = vec4(uintBitsToFloat(raw0), uintBitsToFloat(raw1), uintBitsToFloat(raw2), uintBitsToFloat(raw3));
    return s;
}

void AnnoClip_write(AnnoClipRef ref, AnnoClip s) {
    uint ix = ref.offset >> 2;
    annotated[ix + 0] = floatBitsToUint(s.bbox.x);
    annotated[ix + 1] = floatBitsToUint(s.bbox.y);
    annotated[ix + 2] = floatBitsToUint(s.bbox.z);
    annotated[ix + 3] = floatBitsToUint(s.bbox.w);
}

uint Annotated_tag(AnnotatedRef ref) {
    return annotated[ref.offset >> 2];
}

AnnoStroke Annotated_Stroke_read(AnnotatedRef ref) {
    return AnnoStroke_read(AnnoStrokeRef(ref.offset + 4));
}

AnnoFill Annotated_Fill_read(AnnotatedRef ref) {
    return AnnoFill_read(AnnoFillRef(ref.offset + 4));
}

AnnoClip Annotated_BeginClip_read(AnnotatedRef ref) {
    return AnnoClip_read(AnnoClipRef(ref.offset + 4));
}

AnnoClip Annotated_EndClip_read(AnnotatedRef ref) {
    return AnnoClip_read(AnnoClipRef(ref.offset + 4));
}

void Annotated_Nop_write(AnnotatedRef ref) {
    annotated[ref.offset >> 2] = Annotated_Nop;
}

void Annotated_Stroke_write(AnnotatedRef ref, AnnoStroke s) {
    annotated[ref.offset >> 2] = Annotated_Stroke;
    AnnoStroke_write(AnnoStrokeRef(ref.offset + 4), s);
}

void Annotated_Fill_write(AnnotatedRef ref, AnnoFill s) {
    annotated[ref.offset >> 2] = Annotated_Fill;
    AnnoFill_write(AnnoFillRef(ref.offset + 4), s);
}

void Annotated_BeginClip_write(AnnotatedRef ref, AnnoClip s) {
    annotated[ref.offset >> 2] = Annotated_BeginClip;
    AnnoClip_write(AnnoClipRef(ref.offset + 4), s);
}

void Annotated_EndClip_write(AnnotatedRef ref, AnnoClip s) {
    annotated[ref.offset >> 2] = Annotated_EndClip;
    AnnoClip_write(AnnoClipRef(ref.offset + 4), s);
}

