#pragma once
#include<iostream>
#include<fstream>
#include "Profile.h"
#include "Song.h"
void load_profiles(std::vector<Profile> profiles) {
	std::ifstream load_file;
	load_file.open("Profile.txt", std::ios::in);
	while (!load_file.eof()) {
		Profile input_profile;
		std::string input_string;

		getline(load_file, input_string);
		input_profile.set_profile_name(input_string);
		getline(load_file, input_string);
		input_profile.set_password(input_string);
		getline(load_file, input_string);
		input_profile.set_full_name(input_string);
		getline(load_file, input_string);
		input_profile.set_date_of_birth(input_string);

		int number_of_genres;
		load_file >> number_of_genres;
		int number_of_playlists;
		load_file >> number_of_playlists;
		load_file.ignore(1);

		for (int i = 0; i < number_of_genres; i++) {
			getline(load_file, input_string);
			input_profile.add_genre(input_string);
		}
		for (int i = 0; i < number_of_playlists; i++) {
			Playlist input_playlist;
			getline(load_file, input_string);
			input_playlist.set_name_of_playlist(input_string);

			int size_of_playlist;
			load_file >> size_of_playlist;
			input_playlist.set_maximum_size_of_playlist(size_of_playlist);
			load_file.ignore(1);

			for (unsigned int i = 0; i < input_playlist.get_maximum_size_of_playlist(); i++) {
				Song load_song;
				getline(load_file, input_string);
				load_song.set_name(input_string);
				getline(load_file, input_string);
				load_song.set_author(input_string);
				getline(load_file, input_string);
				load_song.set_genre(input_string);
				getline(load_file, input_string);
				load_song.set_album(input_string);

				int input_release_year;
				double input_rating;
				load_file >> input_release_year;
				load_song.set_release_year(input_release_year);
				load_file >> input_rating;
				load_song.set_rating(input_rating);

				input_playlist.add_song(load_song);
			}
			sort_playlist(input_playlist.get_songs_in_playlist());

			input_profile.add_playlist(input_playlist);
		}
		profiles.push_back(input_profile);
	}
	load_file.close();
}
void save_profiles(std::vector<Profile> load_profiles) {

}
void load_songs(std::vector<Song>& load_songs) {
	std::ifstream load_file;
	load_file.open("Song.txt", std::ios::in);
	while (!load_file.eof()) {
		Song input_song;
		std::string input_string;

		getline(load_file, input_string);
		input_song.set_name(input_string);
		getline(load_file, input_string);
		input_song.set_author(input_string);
		getline(load_file, input_string);
		input_song.set_genre(input_string);
		getline(load_file, input_string);
		input_song.set_album(input_string);

		int input_release_year;
		double input_rating;
		load_file >> input_release_year >> input_rating;
		input_song.set_release_year(input_release_year);
		input_song.set_rating(input_rating);

		load_songs.push_back(input_song);
	}
	load_file.close();
}
void save_songs(std::vector<Song> loaded_songs) {
	std::ofstream save_file;
	save_file.open("Song.txt", std::ios::out);
	while (!loaded_songs.empty()) {
		save_file << loaded_songs.back().get_name() << std::endl;
		save_file << loaded_songs.back().get_author() << std::endl;
		save_file << loaded_songs.back().get_genre() << std::endl;
		save_file << loaded_songs.back().get_album() << std::endl;
		save_file << loaded_songs.back().get_release_year() << std::endl;
		save_file << loaded_songs.back().get_rating() << std::endl;
		loaded_songs.pop_back();
	}
	save_file.close();
}
bool correct_input(std::vector<Profile> loaded_profiles, std::string log_name, std::string log_password) {
	for (unsigned int i = 0; i < loaded_profiles.size(); i++) {
		if (loaded_profiles[i].get_profile_name() == log_name && loaded_profiles[i].get_password() == log_password)return 1;
	}
	return 0;
}
Profile correct_input_profile(std::vector<Profile> loaded_profiles, std::string log_in_name, std::string log_in_password) {
	for (unsigned int i = 0; i < loaded_profiles.size(); i++) {
		if (loaded_profiles[i].get_profile_name() == log_in_name && loaded_profiles[i].get_password() == log_in_password)return loaded_profiles[i];
	}
}
bool exist_playlist(std::vector<Playlist> loaded_playlist, std::string name_of_playlist) {
	for (unsigned int i = 0; i < loaded_playlist.size(); i++) {
		if (loaded_playlist[i].get_name_of_playlist().compare(name_of_playlist) == 0)return 1;
	}
	return 0;
}
Playlist wished_playlist(std::vector<Playlist> loaded_playlist, std::string name_of_playlist) {
	for (unsigned int i = 0; i < loaded_playlist.size(); i++) {
		if (loaded_playlist[i].get_name_of_playlist().compare(name_of_playlist) == 0)return loaded_playlist[i];
	}
}
void musical_collection() {
	std::vector<Profile> loaded_profiles;
	std::vector<Song> loaded_songs;
	load_profiles(loaded_profiles);
	
	Profile current_profile;
	int command;
	do{
		std::cout << "=============================================================================================" << std::endl;
		std::cout << "Welcome to the musical collection! Now you have to options:" << std::endl;
		std::cout << "1 - Log in" << std::endl;
		std::cout << "2 - Sign up" << std::endl;
		std::cout << "3 - Exit from the musical collection" << std::endl;
		std::cout << "=============================================================================================" << std::endl;

		std::cout << "Input the number of command:";
		std::cin >> command;

		switch (command) {
		case 1: {
			std::string log_in_name, log_in_password;
			std::cout << "Type your profile name:";
			std::cin >> log_in_name;
			std::cout << "Type your passoword:";
			std::cin >> log_in_password;
			if (!correct_input(loaded_profiles, log_in_name, log_in_password)) {
				std::cout << "Incorrect profile name or password!" << std::endl;
			}
			else {
				std::cout << "Correct input!" << std::endl;
				load_songs(loaded_songs);

				current_profile = correct_input_profile(loaded_profiles, log_in_name, log_in_password);

				int sub_command;
				do {
					std::cout << "=============================================================================================" << std::endl;
					std::cout << "Main menu of your profile:" << std::endl;
					std::cout << "1 - Change your profile name" << std::endl;
					std::cout << "2 - Change your password" << std::endl;
					std::cout << "3 - Change your full name" << std::endl;
					std::cout << "4 - Change your date of birth" << std::endl;
					std::cout << "5 - Add new favourite genre" << std::endl;
					std::cout << "6 - Delete favourite genre" << std::endl;
					std::cout << "7 - Add a new song" << std::endl;
					std::cout << "8 - Create a new playlist" << std::endl;
					std::cout << "9 - Load a playlist and print songs in the playlist" << std::endl;
					std::cout << "10 - Rate a song" << std::endl;
					std::cout << "11 - Exit from the profile" << std::endl;
					std::cout << "=============================================================================================" << std::endl;

					std::cout << "Type command:";
					std::cin >> sub_command;
					switch (sub_command) {
					case 1: {
						std::string new_profile_name;
						std::cout << "Type your new profile name:";
						std::cin >> new_profile_name;
						current_profile.set_profile_name(new_profile_name);
						break;
					}
					case 2: {
						std::string new_password;
						std::cout << "Type your new password:";
						std::cin >> new_password;
						current_profile.set_password(new_password);
						break;
					}
					case 3: {
						std::string new_full_name;
						std::cout << "Type your new full name:";
						std::cin >> new_full_name;
						current_profile.set_full_name(new_full_name);
						break;
					}
					case 4: {
						std::string new_date_of_birth;
						std::cout << "Type your new date of birth:";
						std::cin >> new_date_of_birth;
						current_profile.set_date_of_birth(new_date_of_birth);
						break;
					}
					case 5: {
						std::string add_new_genre;
						std::cout << "Type the genre you want to add:";
						std::cin >> add_new_genre;
						current_profile.add_genre(add_new_genre);
						break;
					}
					case 6: {
						std::string remove_genre;
						std::cout << "Type the genre you want to remove:";
						std::cin >> remove_genre;
						current_profile.remove_genre(remove_genre);
						break;
					}
					case 7: {
						Song new_song;
						std::string name, author, genre, album;

						std::cout << "Type the name of the song:";
						std::cin >> name;
						new_song.set_name(name);

						std::cout << "Type the author of the song:";
						std::cin >> author;
						new_song.set_author(author);

						std::cout << "Type the genre of the song:";
						std::cin >> genre;
						new_song.set_genre(genre);

						std::cout << "Type the album, in which the song is included:";
						std::cin >> album;
						new_song.set_album(album);

						int release_year;
						std::cout << "Type the year, when the song was released:";
						std::cin >> release_year;
						new_song.set_release_year(release_year);
						
						for (unsigned int i = 0; i < loaded_songs.size(); i++) {
							if (loaded_songs[i].get_name().compare("") == 0) {
								loaded_songs.erase(loaded_songs.begin() + i);
							}
						}

						loaded_songs.push_back(new_song);
						std::cout << "The was successfully added!" << std::endl;

						break;
					}
					case 8: {
						Playlist new_playlist;
						new_playlist.create_playlist(loaded_songs, current_profile.get_genres());
						current_profile.add_playlist(new_playlist);
						break;
					}
					case 9: {
						std::vector<Playlist> load_playlist = current_profile.get_playlist();
						std::string name_of_playlist;
						std::cout << "Type the name of playlist you want to load:";
						std::cin >> name_of_playlist;
						if (exist_playlist(load_playlist, name_of_playlist)) {
							Playlist wanted_playlist = wished_playlist(load_playlist, name_of_playlist);
							wanted_playlist.print();
						}
						else std::cout << "Playlist with this name does not exist!" << std::endl;
						break;
					}
					case 10: {
						std::string name_of_rate_song;
						std::cout << "Type the name of the song you want to rate:";
						std::cin >> name_of_rate_song;

						for (int i = 0; i < loaded_songs.size(); i++) {
							if (loaded_songs[i].get_name().compare(name_of_rate_song) == 0) {
								double rate_song;
								std::cout << "Rate the song:";
								std::cin >> rate_song;
								loaded_songs[i].set_rating(rate_song);
							}
						}
						break;
					}
					case 11: {
						std::cout << "You left your profile!" << std::endl;
						break;
					}
					}
				} while (sub_command != 11);
			}
			save_songs(loaded_songs);
			break;
		}
		case 2: {
			std::cout << "You have to create a new profile!" << std::endl;
			std::string new_profile_name, new_password, new_full_name, new_date_of_birth;

			std::cout << "Type your profile name:";
			std::cin >> new_profile_name;
			current_profile.set_profile_name(new_profile_name);

			std::cout << "Type your password:";
			std::cin >> new_password;
			current_profile.set_password(new_password);

			std::cout << "Type your full name:";
			std::cin >> new_full_name;
			current_profile.set_full_name(new_full_name);

			std::cout << "Type your date of birth:";
			std::cin >> new_date_of_birth;
			current_profile.set_date_of_birth(new_date_of_birth);

			std::cout << "Please log in with your new profile to fill your rest of information up!" << std::endl;
			loaded_profiles.push_back(current_profile);
		}
		case 3: {
			std::cout << "Exit from musical collection program" << std::endl;
			save_profiles(loaded_profiles);
			break;
		}
		}
	} while (command != 3);
}