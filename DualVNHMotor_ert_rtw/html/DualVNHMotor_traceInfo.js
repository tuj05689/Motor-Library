function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "DualVNHMotor"};
	this.sidHashMap["DualVNHMotor"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "DualVNHMotor:10"};
	this.sidHashMap["DualVNHMotor:10"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "DualVNHMotor:2"};
	this.sidHashMap["DualVNHMotor:2"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "DualVNHMotor:3"};
	this.sidHashMap["DualVNHMotor:3"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Subsystem"] = {sid: "DualVNHMotor:10"};
	this.sidHashMap["DualVNHMotor:10"] = {rtwname: "<Root>/Subsystem"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "DualVNHMotor:11"};
	this.sidHashMap["DualVNHMotor:11"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/In2"] = {sid: "DualVNHMotor:12"};
	this.sidHashMap["DualVNHMotor:12"] = {rtwname: "<S1>/In2"};
	this.rtwnameHashMap["<S1>/S-Function Builder"] = {sid: "DualVNHMotor:9"};
	this.sidHashMap["DualVNHMotor:9"] = {rtwname: "<S1>/S-Function Builder"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
