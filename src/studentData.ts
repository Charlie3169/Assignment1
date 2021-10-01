import * as fs from 'fs';
import axios, { AxiosResponse } from 'axios';

interface Students {
    firstName: string;
    lastName: string;
    mNumber?: string;
}

interface Person {
    name: {
        first: string;
        last: string;
    }
}

axios.get('https://randomuser.me/api/?nat=us&results=50').then((response: AxiosResponse) => {
	const data: [Person] = response.data.results;
	for (const person of data) {
		const studentData: Students = {
			firstName: person.name.first,
			lastName: person.name.last,
			mNumber: (Math.floor(Math.random() * 100000000)).toString(),
		};

		fs.appendFileSync('students.txt', `${studentData.firstName} ${studentData.lastName} ${studentData.mNumber}\n`);
	}
});