#pragma once
#include "Song.h"
#include<iostream>
#include<string>
#include<vector>
bool exist_song(std::vector<Song> loaded_songs, std::string name_of_song) {
	for (unsigned int i = 0; i < loaded_songs.size(); i++) {
		if (loaded_songs[i].get_name().compare(name_of_song) == 0)return 1;
	}
	return 0;
}
Song rated_song(std::vector<Song> loaded_songs, std::string name_of_rate_song) {
	for (unsigned int i = 0; i < loaded_songs.size(); i++) {
		if (loaded_songs[i].get_name().compare(name_of_rate_song) == 0)return loaded_songs[i];
	}
}
void sort_playlist(std::vector<Song> songs_in_playlist) {
	for (unsigned int i = 0; i < songs_in_playlist.size(); i++) {
		for (unsigned int j = i + 1; j < songs_in_playlist.size(); j++) {
			if (songs_in_playlist[i].get_name() > songs_in_playlist[i + 1].get_name()) {
				Song temp = songs_in_playlist[i];
				songs_in_playlist[i] = songs_in_playlist[j];
				songs_in_playlist[j] = temp;
			}
		}
	}
}
bool is_favourite_genre(std::string genre,std::vector<std::string> favourite_genres) {
	for (unsigned int i = 0; i < favourite_genres.size(); i++) {
		if (favourite_genres[i].compare(genre) == 0)return 1;
	}
	return 0;
}
class Playlist {
private:
	std::string name_of_playlist;
	unsigned int maximum_size_of_playlist;
	std::vector<Song> songs_in_playlist;

	void copy_playlist(const Playlist&);
	void delete_playlist();
public:
	Playlist();
	Playlist(const Playlist&);
	Playlist& operator=(const Playlist&);
	~Playlist();

	void set_name_of_playlist(std::string);
	void set_maximum_size_of_playlist(int);

	void add_song(Song);

	std::string get_name_of_playlist()const;
	unsigned int get_maximum_size_of_playlist()const;
	std::vector<Song> get_songs_in_playlist()const;

	void create_playlist(std::vector<Song>&,std::vector<std::string>);
	void load_playlist(const std::string&);
	void print()const;
};
void Playlist::copy_playlist(const Playlist& other) {
	name_of_playlist = other.name_of_playlist;
	maximum_size_of_playlist = other.maximum_size_of_playlist;
	songs_in_playlist = other.songs_in_playlist;
}
void Playlist::delete_playlist() {
	name_of_playlist.clear();
	while (!songs_in_playlist.empty()) {
		songs_in_playlist.pop_back();
	}
}
Playlist::Playlist() {
	name_of_playlist = "";
	maximum_size_of_playlist = 0;
	songs_in_playlist = {};
}
Playlist::Playlist(const Playlist& other) {
	copy_playlist(other);
}
Playlist& Playlist::operator=(const Playlist& other) {
	if (this != &other) {
		delete_playlist();
		copy_playlist(other);
	}
	return *this;
}
Playlist::~Playlist() {
	delete_playlist();
}

void Playlist::set_name_of_playlist(std::string other_name_of_playlist) {
	name_of_playlist = other_name_of_playlist;
}
void Playlist::set_maximum_size_of_playlist(int other_maximum_size_of_playlist) {
	maximum_size_of_playlist = other_maximum_size_of_playlist;
}

void Playlist::add_song(Song other_song) {
	songs_in_playlist.push_back(other_song);
}

std::string Playlist::get_name_of_playlist()const {
	return name_of_playlist;
}
unsigned int Playlist::get_maximum_size_of_playlist()const {
	return maximum_size_of_playlist;
}
std::vector<Song> Playlist::get_songs_in_playlist()const {
	return songs_in_playlist;
}

void Playlist::create_playlist(std::vector<Song>& loaded_songs,std::vector<std::string> favourite_genres) {
	Song add_song;

	std::cout << "Name of playlist:";
	std::cin >> name_of_playlist;

	std::cout << "Number of songs in playlist:";
	std::cin >> maximum_size_of_playlist;

	double rating_of_songs_in_playlist;
	std::cout << "Input rating of songs you want to add:";
	std::cin >> rating_of_songs_in_playlist;

	int wished_year;
	int command_table;
	std::cout << "=============================================================================================" << std::endl;
	std::cout << "You have three options to create playsist based on the year you will type after your choice" << std::endl;
	std::cout << "1 - before the year" << std::endl;
	std::cout << "2 - the same year" << std::endl;
	std::cout << "3 - after the year" << std::endl;
	std::cout << "=============================================================================================" << std::endl;
	std::cout << "Type the number of command you want:";
	std::cin >> command_table;
	switch(command_table){
	case 1: {
		std::cout << "Before the year" << std::endl;
		std::cout << "Type the year:";
		std::cin >> wished_year;
		do {
			std::string name_of_song;
			std::cout << "Type name of song:";
			std::cin >> name_of_song;

			if (exist_song(loaded_songs, name_of_song)) {
				add_song = rated_song(loaded_songs, name_of_song);
				if (add_song.get_rating() >= rating_of_songs_in_playlist && add_song.get_release_year() < wished_year) {
					if (is_favourite_genre(add_song.get_genre(), favourite_genres))songs_in_playlist.push_back(add_song);
				}
			}
			else std::cout << "Song is not added in playlist!" << std::endl;
		} while (maximum_size_of_playlist != songs_in_playlist.size());
		break;
	}
	case 2: {
		std::cout << "The same year" << std::endl;
		std::cout << "Type year:";
		std::cin >> wished_year;
		do {
			std::string name_of_song;
			std::cout << "Type name of song:";
			std::cin >> name_of_song;

			if (exist_song(loaded_songs, name_of_song)) {
				add_song = rated_song(loaded_songs, name_of_song);
				if (add_song.get_rating() >= rating_of_songs_in_playlist && add_song.get_release_year() == wished_year) {
					if (is_favourite_genre(add_song.get_genre(), favourite_genres))songs_in_playlist.push_back(add_song);
				}
			}
			else std::cout << "Song is not added in playlist!" << std::endl;
		} while (maximum_size_of_playlist != songs_in_playlist.size());
		break;
	}
	case 3: {
		std::cout << "After the year:";
		std::cout << "Type year:";
		std::cin >> wished_year;
		do {
			std::string name_of_song;
			std::cout << "Type name of song:";
			std::cin >> name_of_song;

			if (exist_song(loaded_songs, name_of_song)) {
				add_song = rated_song(loaded_songs, name_of_song);
				if (add_song.get_rating() >= rating_of_songs_in_playlist && add_song.get_release_year() > wished_year) {
					if (is_favourite_genre(add_song.get_genre(), favourite_genres))songs_in_playlist.push_back(add_song);
				}
			}
			else std::cout << "Song is not added in playlist!" << std::endl;
		} while (maximum_size_of_playlist != songs_in_playlist.size());
		break;
	}
	}
	sort_playlist(songs_in_playlist);
}
void Playlist::load_playlist(const std::string& other_name) {
	if (!name_of_playlist.compare(other_name) == 0) {
		std::cout << "Playlist with this name does not exist!" << std::endl;
	}
	else;
}
void Playlist::print()const {
	for (unsigned int i = 0; i < songs_in_playlist.size(); i++) {
		songs_in_playlist[i].print();
	}
}