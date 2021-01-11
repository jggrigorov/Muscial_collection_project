#pragma once
#include "Playlist.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
class Profile {
private:
	std::string profile_name;
	std::string password;
	std::string full_name;
	std::string date_of_birth;
	std::vector<std::string> genres;
	std::vector<Playlist> playlists;

	void copy_profile(const Profile&);
	void delete_profile();
public:
	Profile();
	Profile(const Profile&);
	Profile& operator=(const Profile&);
	~Profile();

	void set_profile_name(std::string);
	void set_password(std::string);
	void set_full_name(std::string);
	void set_date_of_birth(std::string);

	std::string get_profile_name()const;
	std::string get_password()const;
	std::vector<std::string> get_genres()const;
	std::vector<Playlist> get_playlist()const;

	void add_genre(std::string);
	void remove_genre(std::string);

	void add_playlist(Playlist);

	void print()const;
};
void Profile::copy_profile(const Profile& other) {
	profile_name = other.profile_name;
	password = other.password;
	full_name = other.full_name;
	date_of_birth = other.date_of_birth;
	genres = other.genres;
	playlists = other.playlists;
}
void Profile::delete_profile() {
	profile_name.clear();
	password.clear();
	full_name.clear();
	date_of_birth.clear();
	for (unsigned int i = 0; i < genres.size(); i++) {
		genres[i].clear();
	}
	genres.clear();
}
Profile::Profile() {
	profile_name = "";
	password = "";
	full_name = "";
	date_of_birth = "";
	genres = {};
	playlists = {};
}
Profile::Profile(const Profile& other) {
	copy_profile(other);
}
Profile& Profile::operator=(const Profile& other) {
	if (this != &other) {
		delete_profile();
		copy_profile(other);
	}
	return *this;
}
Profile::~Profile() {
	delete_profile();
}

void Profile::set_profile_name(std::string other_profile_name) {
	profile_name = other_profile_name;
}
void Profile::set_password(std::string other_password) {
	password = other_password;
}
void Profile::set_full_name(std::string other_full_name) {
	full_name = other_full_name;
}
void Profile::set_date_of_birth(std::string other_date_of_birth) {
	date_of_birth = other_date_of_birth;
}

std::string Profile::get_profile_name()const {
	return profile_name;
}
std::string Profile::get_password()const {
	return password;
}
std::vector<std::string> Profile::get_genres()const {
	return genres;
}
std::vector<Playlist> Profile::get_playlist()const {
	return playlists;
}

void Profile::add_genre(std::string name_of_genre) {
	genres.push_back(name_of_genre);
	std::cout << "Genre successfully added!" << std::endl;
}
void Profile::remove_genre(std::string name_of_genre) {
	for(unsigned int i = 0; i < genres.size(); i++) {
		if (genres[i] == name_of_genre) {
			genres.erase(genres.begin() + i);
			std::cout << "Genre successfully removed!" << std::endl;
			return;
		}
	}
	std::cout << "The genre does not contain in the set of genres!" << std::endl;
}

void Profile::add_playlist(Playlist other_playlist) {
	playlists.push_back(other_playlist);
}

void Profile::print()const {
	std::cout << profile_name << std::endl;
	std::cout << password << std::endl;
	std::cout << full_name << std::endl;
	std::cout << date_of_birth << std::endl;
	for (unsigned int i = 0; i < genres.size(); i++) {
		std::cout << genres[i] << std::endl;
	}
	for (unsigned int i = 0; i < playlists.size(); i++) {
		playlists[i].print();
	}
}