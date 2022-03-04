/* ------------------------------------------------------------
copyright: "(c)Romain Michon, CCRMA (Stanford University), GRAME"
license: "MIT"
name: "Clarinet"
Code generated with Faust 2.39.9 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

class mydspSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec18[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			iVec0[l5] = 0;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			iRec18[l6] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec0[0] = 1;
			iRec18[0] = (iVec0[1] + iRec18[1]) % 65536;
			table[i1] = std::sin(9.58738019e-05f * float(iRec18[0]));
			iVec0[1] = iVec0[0];
			iRec18[1] = iRec18[0];
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float mydsp_faustpower2_f(float value) {
	return value * value;
}
static float ftbl0mydspSIG0[65536];

class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int iRec6[2];
	FAUSTFLOAT fHslider1;
	float fRec12[2];
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider2;
	float fConst2;
	float fRec15[2];
	FAUSTFLOAT fHslider3;
	float fConst3;
	FAUSTFLOAT fHslider4;
	int iRec17[2];
	float fRec16[3];
	FAUSTFLOAT fHslider5;
	float fConst4;
	FAUSTFLOAT fHslider6;
	float fRec19[2];
	float fRec13[2];
	FAUSTFLOAT fHslider7;
	int IOTA0;
	float fRec14[2048];
	float fConst5;
	float fConst6;
	FAUSTFLOAT fHslider8;
	float fRec20[2];
	float fVec1[2];
	float fRec11[2];
	float fRec2[2048];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.4");
		m->declare("compile_options", "-lang cpp -es 1 -mcd 16 -single -ftz 0");
		m->declare("copyright", "(c)Romain Michon, CCRMA (Stanford University), GRAME");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("description", "Simple clarinet physical model with physical parameters.");
		m->declare("filename", "clarinet.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "Clarinet");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.3");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.3");
		m->declare("physmodels.lib/name", "Faust Physical Models Library");
		m->declare("physmodels.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.1");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(sample_rate);
		sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 44.0999985f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 3.14159274f / fConst0;
		fConst4 = 1.0f / fConst0;
		fConst5 = 0.00882352982f * fConst0;
		fConst6 = 0.00147058826f * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.10000000000000001f);
		fHslider4 = FAUSTFLOAT(2000.0f);
		fHslider5 = FAUSTFLOAT(0.25f);
		fHslider6 = FAUSTFLOAT(5.0f);
		fHslider7 = FAUSTFLOAT(0.5f);
		fHslider8 = FAUSTFLOAT(0.80000000000000004f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iRec6[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec12[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec15[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			iRec17[l3] = 0;
		}
		for (int l4 = 0; l4 < 3; l4 = l4 + 1) {
			fRec16[l4] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec19[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec13[l8] = 0.0f;
		}
		IOTA0 = 0;
		for (int l9 = 0; l9 < 2048; l9 = l9 + 1) {
			fRec14[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec20[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fVec1[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2048; l13 = l13 + 1) {
			fRec2[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec0[l14] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openHorizontalBox("clarinet");
		ui_interface->openVerticalBox("blower");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->addHorizontalSlider("pressure", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider3, "1", "");
		ui_interface->addHorizontalSlider("breathGain", &fHslider3, FAUSTFLOAT(0.100000001f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider4, "2", "");
		ui_interface->addHorizontalSlider("breathCutoff", &fHslider4, FAUSTFLOAT(2000.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(20000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fHslider6, "3", "");
		ui_interface->addHorizontalSlider("vibratoFreq", &fHslider6, FAUSTFLOAT(5.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fHslider5, "4", "");
		ui_interface->addHorizontalSlider("vibratoGain", &fHslider5, FAUSTFLOAT(0.25f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
		ui_interface->openVerticalBox("clarinetModel");
		ui_interface->declare(&fHslider8, "0", "");
		ui_interface->addHorizontalSlider("tubeLength", &fHslider8, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider7, "1", "");
		ui_interface->addHorizontalSlider("reedStiffness", &fHslider7, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider1, "2", "");
		ui_interface->addHorizontalSlider("bellOpening", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider0, "3", "");
		ui_interface->addHorizontalSlider("outGain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fHslider0);
		float fSlow1 = float(fHslider1);
		float fSlow2 = 1.0f - fSlow1;
		float fSlow3 = fConst1 * float(fHslider2);
		float fSlow4 = std::tan(fConst3 * float(fHslider4));
		float fSlow5 = 1.0f / fSlow4;
		float fSlow6 = (fSlow5 + 1.41421354f) / fSlow4 + 1.0f;
		float fSlow7 = 0.0500000007f * float(fHslider3) / fSlow6;
		float fSlow8 = 1.0f / fSlow6;
		float fSlow9 = (fSlow5 + -1.41421354f) / fSlow4 + 1.0f;
		float fSlow10 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow4));
		float fSlow11 = 0.0299999993f * float(fHslider5);
		float fSlow12 = fConst4 * float(fHslider6);
		float fSlow13 = 0.25999999f * float(fHslider7) + -0.439999998f;
		float fSlow14 = fConst1 * float(fHslider8);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iRec6[0] = 0;
			fRec12[0] = fSlow2 * fRec11[1] + fSlow1 * fRec12[1];
			float fRec10 = fRec12[0] + float(iRec6[1]);
			fRec15[0] = fSlow3 + fConst2 * fRec15[1];
			iRec17[0] = 1103515245 * iRec17[1] + 12345;
			fRec16[0] = 4.65661287e-10f * float(iRec17[0]) - fSlow8 * (fSlow9 * fRec16[2] + fSlow10 * fRec16[1]);
			float fTemp0 = fRec15[0] * (fSlow7 * (fRec16[2] + fRec16[0] + 2.0f * fRec16[1]) + 1.0f);
			fRec19[0] = fSlow12 + fRec19[1] - std::floor(fSlow12 + fRec19[1]);
			float fTemp1 = fSlow11 * ftbl0mydspSIG0[int(65536.0f * fRec19[0])];
			fRec13[0] = fTemp0 + fRec0[1] + fTemp1;
			float fTemp2 = 0.0f - fRec13[1];
			fRec14[IOTA0 & 2047] = fTemp1 + fTemp0 + fTemp2 * std::max<float>(-1.0f, std::min<float>(1.0f, fSlow13 * fTemp2 + 0.699999988f));
			fRec20[0] = fSlow14 + fConst2 * fRec20[1];
			float fTemp3 = fConst6 * (0.5f * fRec20[0] + -0.0500000007f);
			float fTemp4 = fTemp3 + -1.49999499f;
			int iTemp5 = int(fTemp4);
			int iTemp6 = int(std::min<float>(fConst5, float(std::max<int>(0, iTemp5)))) + 1;
			float fTemp7 = std::floor(fTemp4);
			float fTemp8 = fTemp3 + -1.0f - fTemp7;
			float fTemp9 = 0.0f - fTemp8;
			float fTemp10 = fTemp3 + -2.0f - fTemp7;
			float fTemp11 = 0.0f - 0.5f * fTemp10;
			float fTemp12 = fTemp3 + -3.0f - fTemp7;
			float fTemp13 = 0.0f - 0.333333343f * fTemp12;
			float fTemp14 = fTemp3 + -4.0f - fTemp7;
			float fTemp15 = 0.0f - 0.25f * fTemp14;
			float fTemp16 = fTemp3 - fTemp7;
			int iTemp17 = int(std::min<float>(fConst5, float(std::max<int>(0, iTemp5 + 1)))) + 1;
			float fTemp18 = 0.0f - fTemp10;
			float fTemp19 = 0.0f - 0.5f * fTemp12;
			float fTemp20 = 0.0f - 0.333333343f * fTemp14;
			int iTemp21 = int(std::min<float>(fConst5, float(std::max<int>(0, iTemp5 + 2)))) + 1;
			float fTemp22 = 0.0f - fTemp12;
			float fTemp23 = 0.0f - 0.5f * fTemp14;
			float fTemp24 = fTemp8 * fTemp10;
			int iTemp25 = int(std::min<float>(fConst5, float(std::max<int>(0, iTemp5 + 3)))) + 1;
			float fTemp26 = 0.0f - fTemp14;
			float fTemp27 = fTemp24 * fTemp12;
			int iTemp28 = int(std::min<float>(fConst5, float(std::max<int>(0, iTemp5 + 4)))) + 1;
			fVec1[0] = fRec14[(IOTA0 - iTemp6) & 2047] * fTemp9 * fTemp11 * fTemp13 * fTemp15 + fTemp16 * (fRec14[(IOTA0 - iTemp17) & 2047] * fTemp18 * fTemp19 * fTemp20 + 0.5f * fTemp8 * fRec14[(IOTA0 - iTemp21) & 2047] * fTemp22 * fTemp23 + 0.166666672f * fTemp24 * fRec14[(IOTA0 - iTemp25) & 2047] * fTemp26 + 0.0416666679f * fTemp27 * fRec14[(IOTA0 - iTemp28) & 2047]);
			fRec11[0] = fVec1[1];
			float fRec7 = fRec10;
			float fRec8 = fRec11[0];
			float fRec9 = fRec11[0];
			fRec2[IOTA0 & 2047] = fRec7;
			float fRec3 = fTemp9 * fTemp11 * fTemp13 * fTemp15 * fRec2[(IOTA0 - iTemp6) & 2047] + fTemp16 * (fTemp18 * fTemp19 * fTemp20 * fRec2[(IOTA0 - iTemp17) & 2047] + 0.5f * fTemp8 * fTemp22 * fTemp23 * fRec2[(IOTA0 - iTemp21) & 2047] + 0.166666672f * fTemp24 * fTemp26 * fRec2[(IOTA0 - iTemp25) & 2047] + 0.0416666679f * fTemp27 * fRec2[(IOTA0 - iTemp28) & 2047]);
			float fRec4 = fRec8;
			float fRec5 = fRec9;
			fRec0[0] = fRec3;
			float fRec1 = fRec5;
			float fTemp29 = fSlow0 * fRec1;
			output0[i0] = FAUSTFLOAT(fTemp29);
			output1[i0] = FAUSTFLOAT(fTemp29);
			iRec6[1] = iRec6[0];
			fRec12[1] = fRec12[0];
			fRec15[1] = fRec15[0];
			iRec17[1] = iRec17[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec19[1] = fRec19[0];
			fRec13[1] = fRec13[0];
			IOTA0 = IOTA0 + 1;
			fRec20[1] = fRec20[0];
			fVec1[1] = fVec1[0];
			fRec11[1] = fRec11[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
