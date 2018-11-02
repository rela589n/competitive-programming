#pragma once

bool is_spouse(people& person1, people& person2) {

	if (!person1.spouseId							   &&
		!person2.spouseId							   &&
			
		person1.age    <= person2.maxAge			   &&
		person1.age    >= person2.minAge			   &&

		person2.age    <= person1.maxAge			   &&
		person2.age    >= person1.minAge			   &&

		person1.height <= person2.maxHeightOfPartner   &&
		person1.height >= person2.minHeightOfPartner   &&

		person2.height <= person1.maxHeightOfPartner   &&
		person2.height >= person1.minHeightOfPartner   &&

		person1.weight <= person2.maxWeightOfPartner   &&
		person1.weight >= person2.minWeightOfPartner   &&

		person2.weight <= person1.maxWeightOfPartner   &&
		person2.weight >= person1.minWeightOfPartner)
	{
		person1.spouseId = person2.id;
		person2.spouseId = person1.id;

		return true;
	} 

	return false;
}
