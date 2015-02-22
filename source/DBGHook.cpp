#include "DBGHook.h"
#include "FileSystem.h"

// MSS32.DLX function
DBG_VOID lpfn_AIL_get_preference = NULL;
DBG_VOID lpfn_AIL_lock = NULL;
DBG_VOID lpfn_AIL_unlock = NULL;
DBG_VOID lpfn_AIL_lock_mutex = NULL;
DBG_VOID lpfn_AIL_unlock_mutex = NULL;
DBG_VOID lpfn_AIL_get_timer_highest_delay = NULL;
DBG_VOID lpfn_DllMain = NULL;
DBG_VOID lpfn_RIB_load_static_provider_library = NULL;
DBG_VOID lpfnRIB_alloc_provider_handle = NULL;
DBG_VOID lpfnRIB_free_provider_handle = NULL;
DBG_VOID lpfnRIB_load_provider_library = NULL;
DBG_VOID lpfnRIB_free_provider_library = NULL;
DBG_VOID lpfnRIB_register_interface = NULL;
DBG_VOID lpfnRIB_request_interface = NULL;
DBG_VOID lpfnRIB_request_interface_entry = NULL;
DBG_VOID lpfnRIB_unregister_interface = NULL;
DBG_VOID lpfnRIB_enumerate_interface = NULL;
DBG_VOID lpfn_RIB_enumerate_providers = NULL;
DBG_VOID lpfnRIB_type_string = NULL;
DBG_VOID lpfnRIB_find_file_provider = NULL;
DBG_VOID lpfn_RIB_find_files_provider = NULL;
DBG_VOID lpfn_RIB_find_file_dec_provider = NULL;
DBG_VOID lpfn_RIB_find_provider = NULL;
DBG_VOID lpfn_RIB_load_application_providers = NULL;
DBG_VOID lpfn_RIB_set_provider_user_data = NULL;
DBG_VOID lpfn_RIB_provider_user_data = NULL;
DBG_VOID lpfn_RIB_set_provider_system_data = NULL;
DBG_VOID lpfn_RIB_provider_system_data = NULL;
DBG_VOID lpfnRIB_error = NULL;
DBG_VOID lpfn_AIL_set_file_async_callbacks = NULL;
DBG_VOID lpfn_AIL_set_file_callbacks = NULL;
DBG_VOID lpfn_AIL_list_DLS = NULL;
DBG_VOID lpfn_AIL_list_MIDI = NULL;
DBG_VOID lpfnstream_background = NULL;
DBG_VOID lpfn_AIL_ms_count = NULL;
DBG_VOID lpfn_AIL_us_count = NULL;
DBG_VOID lpfn_AIL_MMX_available = NULL;
DBG_VOID lpfnAIL_debug_printf = NULL;
DBG_VOID lpfn_AIL_startup = NULL;
DBG_VOID lpfn_AIL_shutdown = NULL;
DBG_VOID lpfn_AIL_HWND = NULL;
DBG_VOID lpfn_AIL_mem_alloc_lock = NULL;
DBG_VOID lpfn_AIL_mem_free_lock = NULL;
DBG_VOID lpfn_AIL_set_preference = NULL;
DBG_VOID lpfn_AIL_last_error = NULL;
DBG_VOID lpfn_AIL_set_error = NULL;
DBG_VOID lpfn_AIL_delay = NULL;
DBG_VOID lpfn_AIL_background = NULL;
DBG_VOID lpfn_AIL_register_timer = NULL;
DBG_VOID lpfn_AIL_set_timer_user = NULL;
DBG_VOID lpfn_AIL_set_timer_period = NULL;
DBG_VOID lpfn_AIL_set_timer_frequency = NULL;
DBG_VOID lpfn_AIL_set_timer_divisor = NULL;
DBG_VOID lpfn_AIL_start_timer = NULL;
DBG_VOID lpfn_AIL_start_all_timers = NULL;
DBG_VOID lpfn_AIL_stop_timer = NULL;
DBG_VOID lpfn_AIL_stop_all_timers = NULL;
DBG_VOID lpfn_AIL_release_timer_handle = NULL;
DBG_VOID lpfn_AIL_release_all_timers = NULL;
DBG_VOID lpfn_AIL_open_digital_driver = NULL;
DBG_VOID lpfn_AIL_close_digital_driver = NULL;
DBG_VOID lpfn_AIL_waveOutOpen = NULL;
DBG_VOID lpfn_AIL_waveOutClose = NULL;
DBG_VOID lpfn_AIL_digital_handle_release = NULL;
DBG_VOID lpfn_AIL_digital_handle_reacquire = NULL;
DBG_VOID lpfn_AIL_open_input = NULL;
DBG_VOID lpfn_AIL_close_input = NULL;
DBG_VOID lpfn_AIL_get_input_info = NULL;
DBG_VOID lpfn_AIL_set_input_state = NULL;
DBG_VOID lpfn_AIL_digital_CPU_percent = NULL;
DBG_VOID lpfn_AIL_digital_latency = NULL;
DBG_VOID lpfn_AIL_allocate_sample_handle = NULL;
DBG_VOID lpfn_AIL_allocate_file_sample = NULL;
DBG_VOID lpfn_AIL_release_sample_handle = NULL;
DBG_VOID lpfn_AIL_init_sample = NULL;
DBG_VOID lpfn_AIL_set_sample_file = NULL;
DBG_VOID lpfn_AIL_set_named_sample_file = NULL;
DBG_VOID lpfn_AIL_set_sample_processor = NULL;
DBG_VOID lpfn_AIL_set_stream_processor = NULL;
DBG_VOID lpfn_AIL_set_DLS_processor = NULL;
DBG_VOID lpfn_AIL_set_digital_driver_processor = NULL;
DBG_VOID lpfn_AIL_set_sample_address = NULL;
DBG_VOID lpfn_AIL_set_sample_type = NULL;
DBG_VOID lpfn_AIL_set_sample_adpcm_block_size = NULL;
DBG_VOID lpfn_AIL_start_sample = NULL;
DBG_VOID lpfn_AIL_stop_sample = NULL;
DBG_VOID lpfn_AIL_resume_sample = NULL;
DBG_VOID lpfn_AIL_end_sample = NULL;
DBG_VOID lpfn_AIL_set_sample_playback_rate = NULL;
DBG_VOID lpfn_AIL_set_sample_volume_pan = NULL;
DBG_VOID lpfn_AIL_set_sample_volume_levels = NULL;
DBG_VOID lpfn_AIL_set_sample_reverb_levels = NULL;
DBG_VOID lpfn_AIL_set_sample_low_pass_cut_off = NULL;
DBG_VOID lpfn_AIL_set_sample_loop_count = NULL;
DBG_VOID lpfn_AIL_set_sample_loop_block = NULL;
DBG_VOID lpfn_AIL_sample_status = NULL;
DBG_VOID lpfn_AIL_sample_playback_rate = NULL;
DBG_VOID lpfn_AIL_sample_volume_pan = NULL;
DBG_VOID lpfn_AIL_sample_volume_levels = NULL;
DBG_VOID lpfn_AIL_sample_reverb_levels = NULL;
DBG_VOID lpfn_AIL_sample_low_pass_cut_off = NULL;
DBG_VOID lpfn_AIL_sample_loop_count = NULL;
DBG_VOID lpfn_AIL_set_digital_master_volume_level = NULL;
DBG_VOID lpfn_AIL_digital_master_volume_level = NULL;
DBG_VOID lpfn_AIL_set_digital_master_reverb_levels = NULL;
DBG_VOID lpfn_AIL_set_digital_master_room_type = NULL;
DBG_VOID lpfn_AIL_digital_master_reverb_levels = NULL;
DBG_VOID lpfn_AIL_set_digital_master_reverb = NULL;
DBG_VOID lpfn_AIL_digital_master_reverb = NULL;
DBG_VOID lpfn_AIL_minimum_sample_buffer_size = NULL;
DBG_VOID lpfn_AIL_sample_buffer_ready = NULL;
DBG_VOID lpfn_AIL_load_sample_buffer = NULL;
DBG_VOID lpfn_AIL_sample_buffer_info = NULL;
DBG_VOID lpfn_AIL_sample_granularity = NULL;
DBG_VOID lpfn_AIL_set_sample_position = NULL;
DBG_VOID lpfn_AIL_sample_position = NULL;
DBG_VOID lpfn_AIL_register_SOB_callback = NULL;
DBG_VOID lpfn_AIL_register_EOB_callback = NULL;
DBG_VOID lpfn_AIL_register_EOS_callback = NULL;
DBG_VOID lpfn_AIL_register_EOF_callback = NULL;
DBG_VOID lpfn_AIL_set_sample_user_data = NULL;
DBG_VOID lpfn_AIL_sample_user_data = NULL;
DBG_VOID lpfn_AIL_active_sample_count = NULL;
DBG_VOID lpfn_AIL_digital_configuration = NULL;
DBG_VOID lpfn_AIL_get_DirectSound_info = NULL;
DBG_VOID lpfn_AIL_set_DirectSound_HWND = NULL;
DBG_VOID lpfn_AIL_open_XMIDI_driver = NULL;
DBG_VOID lpfn_AIL_close_XMIDI_driver = NULL;
DBG_VOID lpfn_AIL_midiOutOpen = NULL;
DBG_VOID lpfn_AIL_midiOutClose = NULL;
DBG_VOID lpfn_AIL_MIDI_handle_release = NULL;
DBG_VOID lpfn_AIL_MIDI_handle_reacquire = NULL;
DBG_VOID lpfn_AIL_allocate_sequence_handle = NULL;
DBG_VOID lpfn_AIL_release_sequence_handle = NULL;
DBG_VOID lpfn_AIL_init_sequence = NULL;
DBG_VOID lpfn_AIL_start_sequence = NULL;
DBG_VOID lpfn_AIL_stop_sequence = NULL;
DBG_VOID lpfn_AIL_resume_sequence = NULL;
DBG_VOID lpfn_AIL_end_sequence = NULL;
DBG_VOID lpfn_AIL_set_sequence_tempo = NULL;
DBG_VOID lpfn_AIL_set_sequence_volume = NULL;
DBG_VOID lpfn_AIL_set_sequence_loop_count = NULL;
DBG_VOID lpfn_AIL_sequence_status = NULL;
DBG_VOID lpfn_AIL_sequence_tempo = NULL;
DBG_VOID lpfn_AIL_sequence_volume = NULL;
DBG_VOID lpfn_AIL_sequence_loop_count = NULL;
DBG_VOID lpfn_AIL_set_XMIDI_master_volume = NULL;
DBG_VOID lpfn_AIL_XMIDI_master_volume = NULL;
DBG_VOID lpfn_AIL_active_sequence_count = NULL;
DBG_VOID lpfn_AIL_controller_value = NULL;
DBG_VOID lpfn_AIL_channel_notes = NULL;
DBG_VOID lpfn_AIL_sequence_position = NULL;
DBG_VOID lpfn_AIL_branch_index = NULL;
DBG_VOID lpfn_AIL_register_prefix_callback = NULL;
DBG_VOID lpfn_AIL_register_trigger_callback = NULL;
DBG_VOID lpfn_AIL_register_sequence_callback = NULL;
DBG_VOID lpfn_AIL_register_beat_callback = NULL;
DBG_VOID lpfn_AIL_register_event_callback = NULL;
DBG_VOID lpfn_AIL_register_timbre_callback = NULL;
DBG_VOID lpfn_AIL_set_sequence_user_data = NULL;
DBG_VOID lpfn_AIL_sequence_user_data = NULL;
DBG_VOID lpfn_AIL_register_ICA_array = NULL;
DBG_VOID lpfn_AIL_lock_channel = NULL;
DBG_VOID lpfn_AIL_release_channel = NULL;
DBG_VOID lpfn_AIL_map_sequence_channel = NULL;
DBG_VOID lpfn_AIL_true_sequence_channel = NULL;
DBG_VOID lpfn_AIL_send_channel_voice_message = NULL;
DBG_VOID lpfn_AIL_send_sysex_message = NULL;
DBG_VOID lpfn_AIL_create_wave_synthesizer = NULL;
DBG_VOID lpfn_AIL_destroy_wave_synthesizer = NULL;
DBG_VOID lpfn_AIL_file_error = NULL;
DBG_VOID lpfn_AIL_file_size = NULL;
DBG_VOID lpfn_AIL_file_read = NULL;
DBG_VOID lpfn_AIL_file_write = NULL;
DBG_VOID lpfn_AIL_WAV_file_write = NULL;
DBG_VOID lpfn_AIL_serve = NULL;
DBG_VOID lpfn_AIL_redbook_open = NULL;
DBG_VOID lpfn_AIL_redbook_open_drive = NULL;
DBG_VOID lpfn_AIL_redbook_close = NULL;
DBG_VOID lpfn_AIL_redbook_eject = NULL;
DBG_VOID lpfn_AIL_redbook_retract = NULL;
DBG_VOID lpfn_AIL_redbook_status = NULL;
DBG_VOID lpfn_AIL_redbook_tracks = NULL;
DBG_VOID lpfn_AIL_redbook_track = NULL;
DBG_VOID lpfn_AIL_redbook_track_info = NULL;
DBG_VOID lpfn_AIL_redbook_id = NULL;
DBG_VOID lpfn_AIL_redbook_position = NULL;
DBG_VOID lpfn_AIL_redbook_play = NULL;
DBG_VOID lpfn_AIL_redbook_stop = NULL;
DBG_VOID lpfn_AIL_redbook_pause = NULL;
DBG_VOID lpfn_AIL_redbook_resume = NULL;
DBG_VOID lpfn_AIL_redbook_volume_level = NULL;
DBG_VOID lpfn_AIL_redbook_set_volume_level = NULL;
DBG_VOID lpfn_AIL_quick_startup = NULL;
DBG_VOID lpfn_AIL_quick_shutdown = NULL;
DBG_VOID lpfn_AIL_quick_handles = NULL;
DBG_VOID lpfn_AIL_quick_load = NULL;
DBG_VOID lpfn_AIL_quick_load_mem = NULL;
DBG_VOID lpfn_AIL_quick_copy = NULL;
DBG_VOID lpfn_AIL_quick_unload = NULL;
DBG_VOID lpfn_AIL_quick_play = NULL;
DBG_VOID lpfn_AIL_quick_halt = NULL;
DBG_VOID lpfn_AIL_quick_status = NULL;
DBG_VOID lpfn_AIL_quick_load_and_play = NULL;
DBG_VOID lpfn_AIL_quick_set_speed = NULL;
DBG_VOID lpfn_AIL_quick_set_volume = NULL;
DBG_VOID lpfn_AIL_quick_set_reverb_levels = NULL;
DBG_VOID lpfn_AIL_quick_set_low_pass_cut_off = NULL;
DBG_VOID lpfn_AIL_open_stream = NULL;
DBG_VOID lpfn_AIL_close_stream = NULL;
DBG_VOID lpfn_AIL_service_stream = NULL;
DBG_VOID lpfn_AIL_start_stream = NULL;
DBG_VOID lpfn_AIL_pause_stream = NULL;
DBG_VOID lpfn_AIL_set_stream_volume_pan = NULL;
DBG_VOID lpfn_AIL_set_stream_volume_levels = NULL;
DBG_VOID lpfn_AIL_set_stream_reverb_levels = NULL;
DBG_VOID lpfn_AIL_set_stream_low_pass_cut_off = NULL;
DBG_VOID lpfn_AIL_stream_volume_pan = NULL;
DBG_VOID lpfn_AIL_stream_volume_levels = NULL;
DBG_VOID lpfn_AIL_stream_reverb_levels = NULL;
DBG_VOID lpfn_AIL_stream_low_pass_cut_off = NULL;
DBG_VOID lpfn_AIL_set_stream_playback_rate = NULL;
DBG_VOID lpfn_AIL_stream_playback_rate = NULL;
DBG_VOID lpfn_AIL_stream_loop_count = NULL;
DBG_VOID lpfn_AIL_set_stream_loop_block = NULL;
DBG_VOID lpfn_AIL_set_stream_loop_count = NULL;
DBG_VOID lpfn_AIL_stream_status = NULL;
DBG_VOID lpfn_AIL_set_stream_position = NULL;
DBG_VOID lpfn_AIL_stream_position = NULL;
DBG_VOID lpfn_AIL_stream_info = NULL;
DBG_VOID lpfn_AIL_register_stream_callback = NULL;
DBG_VOID lpfn_AIL_auto_service_stream = NULL;
DBG_VOID lpfn_AIL_set_stream_user_data = NULL;
DBG_VOID lpfn_AIL_stream_user_data = NULL;
DBG_VOID lpfn_AIL_DLS_open = NULL;
DBG_VOID lpfn_AIL_DLS_close = NULL;
DBG_VOID lpfn_AIL_DLS_load_file = NULL;
DBG_VOID lpfn_AIL_DLS_load_memory = NULL;
DBG_VOID lpfn_AIL_DLS_unload = NULL;
DBG_VOID lpfn_AIL_DLS_compact = NULL;
DBG_VOID lpfn_AIL_DLS_set_reverb_levels = NULL;
DBG_VOID lpfn_AIL_DLS_get_reverb_levels = NULL;
DBG_VOID lpfn_AIL_DLS_get_info = NULL;
DBG_VOID lpfn_AIL_set_sequence_ms_position = NULL;
DBG_VOID lpfn_AIL_sequence_ms_position = NULL;
DBG_VOID lpfn_AIL_sample_ms_position = NULL;
DBG_VOID lpfn_AIL_set_sample_ms_position = NULL;
DBG_VOID lpfn_AIL_stream_ms_position = NULL;
DBG_VOID lpfn_AIL_set_stream_ms_position = NULL;
DBG_VOID lpfn_AIL_quick_set_ms_position = NULL;
DBG_VOID lpfn_AIL_quick_ms_position = NULL;
DBG_VOID lpfn_AIL_quick_ms_length = NULL;
DBG_VOID lpfn_AIL_quick_type = NULL;
DBG_VOID lpfn_AIL_MIDI_to_XMI = NULL;
DBG_VOID lpfn_AIL_compress_ADPCM = NULL;
DBG_VOID lpfn_AIL_decompress_ADPCM = NULL;
DBG_VOID lpfn_AIL_WAV_info = NULL;
DBG_VOID lpfn_AIL_file_type = NULL;
DBG_VOID lpfn_AIL_find_DLS = NULL;
DBG_VOID lpfn_AIL_extract_DLS = NULL;
DBG_VOID lpfn_AIL_primary_digital_driver = NULL;
DBG_VOID lpfn_AIL_enumerate_filters = NULL;
DBG_VOID lpfn_AIL_open_filter = NULL;
DBG_VOID lpfn_AIL_close_filter = NULL;
DBG_VOID lpfn_AIL_enumerate_filter_attributes = NULL;
DBG_VOID lpfn_AIL_enumerate_filter_sample_attribute = NULL;
DBG_VOID lpfn_AIL_filter_attribute = NULL;
DBG_VOID lpfn_AIL_filter_sample_attribute = NULL;
DBG_VOID lpfn_AIL_filter_stream_attribute = NULL;
DBG_VOID lpfn_AIL_filter_DLS_attribute = NULL;
DBG_VOID lpfn_AIL_set_filter_preference = NULL;
DBG_VOID lpfn_AIL_set_filter_sample_preference = NULL;
DBG_VOID lpfn_AIL_set_filter_stream_preference = NULL;
DBG_VOID lpfn_AIL_set_filter_DLS_preference = NULL;
DBG_VOID lpfn_AIL_enumerate_3D_providers = NULL;
DBG_VOID lpfn_AIL_open_3D_provider = NULL;
DBG_VOID lpfn_AIL_close_3D_provider = NULL;
DBG_VOID lpfn_AIL_enumerate_3D_provider_attributes = NULL;
DBG_VOID lpfn_AIL_enumerate_3D_sample_attributes = NULL;
DBG_VOID lpfn_AIL_3D_provider_attribute = NULL;
DBG_VOID lpfn_AIL_3D_sample_attribute = NULL;
DBG_VOID lpfn_AIL_set_3D_provider_preference = NULL;
DBG_VOID lpfn_AIL_set_3D_sample_preference = NULL;
DBG_VOID lpfn_AIL_allocate_3D_sample_handle = NULL;
DBG_VOID lpfn_AIL_release_3D_sample_handle = NULL;
DBG_VOID lpfn_AIL_start_3D_sample = NULL;
DBG_VOID lpfn_AIL_stop_3D_sample = NULL;
DBG_VOID lpfn_AIL_resume_3D_sample = NULL;
DBG_VOID lpfn_AIL_end_3D_sample = NULL;
DBG_VOID lpfn_AIL_set_3D_sample_info = NULL;
DBG_VOID lpfn_AIL_set_3D_sample_file = NULL;
DBG_VOID lpfn_AIL_set_3D_sample_volume = NULL;
DBG_VOID lpfn_AIL_set_3D_sample_playback_rate = NULL;
DBG_VOID lpfn_AIL_set_3D_sample_offset = NULL;
DBG_VOID lpfn_AIL_set_3D_sample_loop_count = NULL;
DBG_VOID lpfn_AIL_set_3D_sample_loop_block = NULL;
DBG_VOID lpfn_AIL_set_3D_sample_obstruction = NULL;
DBG_VOID lpfn_AIL_set_3D_sample_exclusion = NULL;
DBG_VOID lpfn_AIL_set_3D_sample_occlusion = NULL;
DBG_VOID lpfn_AIL_set_3D_sample_cone = NULL;
DBG_VOID lpfn_AIL_set_3D_sample_effects_level = NULL;
DBG_VOID lpfn_AIL_register_3D_EOS_callback = NULL;
DBG_VOID lpfn_AIL_3D_sample_obstruction = NULL;
DBG_VOID lpfn_AIL_3D_sample_exclusion = NULL;
DBG_VOID lpfn_AIL_3D_sample_occlusion = NULL;
DBG_VOID lpfn_AIL_3D_sample_cone = NULL;
DBG_VOID lpfn_AIL_3D_sample_effects_level = NULL;
DBG_VOID lpfn_AIL_3D_sample_status = NULL;
DBG_VOID lpfn_AIL_3D_sample_volume = NULL;
DBG_VOID lpfn_AIL_3D_sample_playback_rate = NULL;
DBG_VOID lpfn_AIL_3D_sample_offset = NULL;
DBG_VOID lpfn_AIL_3D_sample_length = NULL;
DBG_VOID lpfn_AIL_3D_sample_loop_count = NULL;
DBG_VOID lpfn_AIL_set_3D_sample_distances = NULL;
DBG_VOID lpfn_AIL_3D_sample_distances = NULL;
DBG_VOID lpfn_AIL_set_3D_user_data = NULL;
DBG_VOID lpfn_AIL_3D_user_data = NULL;
DBG_VOID lpfn_AIL_active_3D_sample_count = NULL;
DBG_VOID lpfn_AIL_3D_room_type = NULL;
DBG_VOID lpfn_AIL_set_3D_room_type = NULL;
DBG_VOID lpfn_AIL_3D_speaker_type = NULL;
DBG_VOID lpfn_AIL_set_3D_speaker_type = NULL;
DBG_VOID lpfn_AIL_3D_rolloff_factor = NULL;
DBG_VOID lpfn_AIL_set_3D_rolloff_factor = NULL;
DBG_VOID lpfn_AIL_3D_doppler_factor = NULL;
DBG_VOID lpfn_AIL_set_3D_doppler_factor = NULL;
DBG_VOID lpfn_AIL_3D_distance_factor = NULL;
DBG_VOID lpfn_AIL_set_3D_distance_factor = NULL;
DBG_VOID lpfn_AIL_open_3D_listener = NULL;
DBG_VOID lpfn_AIL_close_3D_listener = NULL;
DBG_VOID lpfn_AIL_open_3D_object = NULL;
DBG_VOID lpfn_AIL_close_3D_object = NULL;
DBG_VOID lpfn_AIL_set_3D_position = NULL;
DBG_VOID lpfn_AIL_set_3D_velocity = NULL;
DBG_VOID lpfn_AIL_set_3D_velocity_vector = NULL;
DBG_VOID lpfn_AIL_set_3D_orientation = NULL;
DBG_VOID lpfn_AIL_3D_position = NULL;
DBG_VOID lpfn_AIL_3D_velocity = NULL;
DBG_VOID lpfn_AIL_3D_orientation = NULL;
DBG_VOID lpfn_AIL_update_3D_position = NULL;
DBG_VOID lpfn_AIL_auto_update_3D_position = NULL;
DBG_VOID lpfn_AIL_size_processed_digital_audio = NULL;
DBG_VOID lpfn_AIL_process_digital_audio = NULL;
DBG_VOID lpfn_AIL_merge_DLS_with_XMI = NULL;
DBG_VOID lpfn_AIL_compress_DLS = NULL;
DBG_VOID lpfn_AIL_filter_DLS_with_XMI = NULL;
DBG_VOID lpfn_AIL_compress_ASI = NULL;
DBG_VOID lpfn_AIL_decompress_ASI = NULL;
DBG_VOID lpfn_AIL_request_EOB_ASI_reset = NULL;
DBG_VOID lpfn_AIL_set_redist_directory = NULL;
DBG_VOID lpfn_MIX_RIB_MAIN = NULL;
DBG_VOID lpfn_AIL_mem_use_malloc = NULL;
DBG_VOID lpfn_AIL_mem_use_free = NULL;
DBG_VOID lpfnAIL_sprintf = NULL;
DBG_VOID lpfnDLSMSSOpen = NULL;
DBG_VOID lpfnDLSClose = NULL;
DBG_VOID lpfnDLSLoadFile = NULL;
DBG_VOID lpfnDLSLoadMemFile = NULL;
DBG_VOID lpfnDLSGetInfo = NULL;
DBG_VOID lpfnDLSCompactMemory = NULL;
DBG_VOID lpfnDLSUnloadAll = NULL;
DBG_VOID lpfnDLSUnloadFile = NULL;
DBG_VOID lpfnDLSSetAttribute = NULL;
DBG_VOID lpfn_DLSMSSGetCPU = NULL;
/*
// Global addresses of IJL.dat functions
IJL_VOID lpfnIJLGetLibVersion = NULL;
IJL_VOID lpfnIJLInit = NULL;
IJL_VOID lpfnIJLFree = NULL;
IJL_VOID lpfnIJLRead = NULL;
IJL_VOID lpfnIJLWrite = NULL;
IJL_VOID lpfnIJLErrorStr = NULL;
*/

// Screenshot quality mod setting
DWORD ssQuality = 75;

//-------------------------------------------
// Methods

CDBGHook::~CDBGHook()
{
	if ( hDBG != NULL ) {
		FreeLibrary( hDBG );
	}
}

bool CDBGHook::Hook()
{
/*
	wstring ijlDat=GetCurPath();
	ijlDat+=L"\\ijl15.dat";
	
	hIJL = LoadLibrary(ijlDat.c_str());
	if (hIJL == NULL)
	{
		DebugLog("Failed to load IJL.dat.\n");
		WriteLog("IJL hook installation failed.\n");
		return false;
	}
*/
/*
	lpfnIJLGetLibVersion	= (IJL_VOID)(DBG_VOID)GetProcAddress(hIJL, "ijlGetLibVersion");
	lpfnIJLInit				= (IJL_VOID)(DBG_VOID)GetProcAddress(hIJL, "ijlInit");
	lpfnIJLFree				= (IJL_VOID)(DBG_VOID)GetProcAddress(hIJL, "ijlFree");
	lpfnIJLRead				= (IJL_VOID)(DBG_VOID)GetProcAddress(hIJL, "ijlRead");
	lpfnIJLWrite			= (IJL_VOID)(DBG_VOID)GetProcAddress(hIJL, "ijlWrite");
	lpfnIJLErrorStr			= (IJL_VOID)(DBG_VOID)GetProcAddress(hIJL, "ijlErrorStr");
*/
	wstring dllPath;
	dllPath += GetCurPath();
	dllPath += L"\\Mss32.DLX";

	DebugLog("%ls에서 Mss32.dlx 파일을 로딩합니다.\n", GetCurPath().c_str());
	DebugLog("로그가 여기서 끊긴다면 Mss32.dlx 파일이 있는지 확인해주세요.\n");

	hDBG = LoadLibrary(dllPath.c_str());
	if (hDBG == NULL)
	{
		DebugLog("Mss32.DLX 파일 로딩에 실패했습니다.\n");
		WriteLog("Mss32 Hook 설치가 실패했습니다.\n");
		return false;
	}
	
	WriteLog("Mss32 Hook 설치를 시작합니다.\n");


	lpfn_AIL_get_preference                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_get_preference@4");
	lpfn_AIL_lock                             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_lock@0");
	lpfn_AIL_unlock                           = (DBG_VOID)GetProcAddress(hDBG, "_AIL_unlock@0");
	lpfn_AIL_lock_mutex                       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_lock_mutex@0");
	lpfn_AIL_unlock_mutex                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_unlock_mutex@0");
	lpfn_AIL_get_timer_highest_delay          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_get_timer_highest_delay@0");
	lpfn_DllMain                              = (DBG_VOID)GetProcAddress(hDBG, "_DllMain@12");
	lpfn_RIB_load_static_provider_library     = (DBG_VOID)GetProcAddress(hDBG, "_RIB_load_static_provider_library@8");
	lpfnRIB_alloc_provider_handle             = (DBG_VOID)GetProcAddress(hDBG, "RIB_alloc_provider_handle");
	lpfnRIB_free_provider_handle              = (DBG_VOID)GetProcAddress(hDBG, "RIB_free_provider_handle");
	lpfnRIB_load_provider_library             = (DBG_VOID)GetProcAddress(hDBG, "RIB_load_provider_library");
	lpfnRIB_free_provider_library             = (DBG_VOID)GetProcAddress(hDBG, "RIB_free_provider_library");
	lpfnRIB_register_interface                = (DBG_VOID)GetProcAddress(hDBG, "RIB_register_interface");
	lpfnRIB_request_interface                 = (DBG_VOID)GetProcAddress(hDBG, "RIB_request_interface");
	lpfnRIB_request_interface_entry           = (DBG_VOID)GetProcAddress(hDBG, "RIB_request_interface_entry");
	lpfnRIB_unregister_interface              = (DBG_VOID)GetProcAddress(hDBG, "RIB_unregister_interface");
	lpfnRIB_enumerate_interface               = (DBG_VOID)GetProcAddress(hDBG, "RIB_enumerate_interface");
	lpfn_RIB_enumerate_providers              = (DBG_VOID)GetProcAddress(hDBG, "_RIB_enumerate_providers@12");
	lpfnRIB_type_string                       = (DBG_VOID)GetProcAddress(hDBG, "RIB_type_string");
	lpfnRIB_find_file_provider                = (DBG_VOID)GetProcAddress(hDBG, "RIB_find_file_provider");
	lpfn_RIB_find_files_provider              = (DBG_VOID)GetProcAddress(hDBG, "_RIB_find_files_provider@20");
	lpfn_RIB_find_file_dec_provider           = (DBG_VOID)GetProcAddress(hDBG, "_RIB_find_file_dec_provider@20");
	lpfn_RIB_find_provider                    = (DBG_VOID)GetProcAddress(hDBG, "_RIB_find_provider@12");
	lpfn_RIB_load_application_providers       = (DBG_VOID)GetProcAddress(hDBG, "_RIB_load_application_providers@4");
	lpfn_RIB_set_provider_user_data           = (DBG_VOID)GetProcAddress(hDBG, "_RIB_set_provider_user_data@12");
	lpfn_RIB_provider_user_data               = (DBG_VOID)GetProcAddress(hDBG, "_RIB_provider_user_data@8");
	lpfn_RIB_set_provider_system_data         = (DBG_VOID)GetProcAddress(hDBG, "_RIB_set_provider_system_data@12");
	lpfn_RIB_provider_system_data             = (DBG_VOID)GetProcAddress(hDBG, "_RIB_provider_system_data@8");
	lpfnRIB_error                             = (DBG_VOID)GetProcAddress(hDBG, "RIB_error");
	lpfn_AIL_set_file_async_callbacks         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_file_async_callbacks@20");
	lpfn_AIL_set_file_callbacks               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_file_callbacks@16");
	lpfn_AIL_list_DLS                         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_list_DLS@20");
	lpfn_AIL_list_MIDI                        = (DBG_VOID)GetProcAddress(hDBG, "_AIL_list_MIDI@20");
	lpfnstream_background                     = (DBG_VOID)GetProcAddress(hDBG, "stream_background");
	lpfn_AIL_ms_count                         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_ms_count@0");
	lpfn_AIL_us_count                         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_us_count@0");
	lpfn_AIL_MMX_available                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_MMX_available@0");
	lpfnAIL_debug_printf                      = (DBG_VOID)GetProcAddress(hDBG, "AIL_debug_printf");
	lpfn_AIL_startup                          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_startup@0");
	lpfn_AIL_shutdown                         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_shutdown@0");
	lpfn_AIL_HWND                             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_HWND@0");
	lpfn_AIL_mem_alloc_lock                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_mem_alloc_lock@4");
	lpfn_AIL_mem_free_lock                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_mem_free_lock@4");
	lpfn_AIL_set_preference                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_preference@8");
	lpfn_AIL_last_error                       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_last_error@0");
	lpfn_AIL_set_error                        = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_error@4");
	lpfn_AIL_delay                            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_delay@4");
	lpfn_AIL_background                       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_background@0");
	lpfn_AIL_register_timer                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_register_timer@4");
	lpfn_AIL_set_timer_user                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_timer_user@8");
	lpfn_AIL_set_timer_period                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_timer_period@8");
	lpfn_AIL_set_timer_frequency              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_timer_frequency@8");
	lpfn_AIL_set_timer_divisor                = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_timer_divisor@8");
	lpfn_AIL_start_timer                      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_start_timer@4");
	lpfn_AIL_start_all_timers                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_start_all_timers@0");
	lpfn_AIL_stop_timer                       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stop_timer@4");
	lpfn_AIL_stop_all_timers                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stop_all_timers@0");
	lpfn_AIL_release_timer_handle             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_release_timer_handle@4");
	lpfn_AIL_release_all_timers               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_release_all_timers@0");
	lpfn_AIL_open_digital_driver              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_open_digital_driver@16");
	lpfn_AIL_close_digital_driver             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_close_digital_driver@4");
	lpfn_AIL_waveOutOpen                      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_waveOutOpen@16");
	lpfn_AIL_waveOutClose                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_waveOutClose@4");
	lpfn_AIL_digital_handle_release           = (DBG_VOID)GetProcAddress(hDBG, "_AIL_digital_handle_release@4");
	lpfn_AIL_digital_handle_reacquire         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_digital_handle_reacquire@4");
	lpfn_AIL_open_input                       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_open_input@4");
	lpfn_AIL_close_input                      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_close_input@4");
	lpfn_AIL_get_input_info                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_get_input_info@4");
	lpfn_AIL_set_input_state                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_input_state@8");
	lpfn_AIL_digital_CPU_percent              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_digital_CPU_percent@4");
	lpfn_AIL_digital_latency                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_digital_latency@4");
	lpfn_AIL_allocate_sample_handle           = (DBG_VOID)GetProcAddress(hDBG, "_AIL_allocate_sample_handle@4");
	lpfn_AIL_allocate_file_sample             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_allocate_file_sample@12");
	lpfn_AIL_release_sample_handle            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_release_sample_handle@4");
	lpfn_AIL_init_sample                      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_init_sample@4");
	lpfn_AIL_set_sample_file                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sample_file@12");
	lpfn_AIL_set_named_sample_file            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_named_sample_file@20");
	lpfn_AIL_set_sample_processor             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sample_processor@12");
	lpfn_AIL_set_stream_processor             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_stream_processor@12");
	lpfn_AIL_set_DLS_processor                = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_DLS_processor@12");
	lpfn_AIL_set_digital_driver_processor     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_digital_driver_processor@12");
	lpfn_AIL_set_sample_address               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sample_address@12");
	lpfn_AIL_set_sample_type                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sample_type@12");
	lpfn_AIL_set_sample_adpcm_block_size      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sample_adpcm_block_size@8");
	lpfn_AIL_start_sample                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_start_sample@4");
	lpfn_AIL_stop_sample                      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stop_sample@4");
	lpfn_AIL_resume_sample                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_resume_sample@4");
	lpfn_AIL_end_sample                       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_end_sample@4");
	lpfn_AIL_set_sample_playback_rate         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sample_playback_rate@8");
	lpfn_AIL_set_sample_volume_pan            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sample_volume_pan@12");
	lpfn_AIL_set_sample_volume_levels         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sample_volume_levels@12");
	lpfn_AIL_set_sample_reverb_levels         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sample_reverb_levels@12");
	lpfn_AIL_set_sample_low_pass_cut_off      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sample_low_pass_cut_off@8");
	lpfn_AIL_set_sample_loop_count            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sample_loop_count@8");
	lpfn_AIL_set_sample_loop_block            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sample_loop_block@12");
	lpfn_AIL_sample_status                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sample_status@4");
	lpfn_AIL_sample_playback_rate             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sample_playback_rate@4");
	lpfn_AIL_sample_volume_pan                = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sample_volume_pan@12");
	lpfn_AIL_sample_volume_levels             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sample_volume_levels@12");
	lpfn_AIL_sample_reverb_levels             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sample_reverb_levels@12");
	lpfn_AIL_sample_low_pass_cut_off          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sample_low_pass_cut_off@4");
	lpfn_AIL_sample_loop_count                = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sample_loop_count@4");
	lpfn_AIL_set_digital_master_volume_level  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_digital_master_volume_level@8");
	lpfn_AIL_digital_master_volume_level      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_digital_master_volume_level@4");
	lpfn_AIL_set_digital_master_reverb_levels = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_digital_master_reverb_levels@12");
	lpfn_AIL_set_digital_master_room_type     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_digital_master_room_type@8");
	lpfn_AIL_digital_master_reverb_levels     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_digital_master_reverb_levels@12");
	lpfn_AIL_set_digital_master_reverb        = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_digital_master_reverb@16");
	lpfn_AIL_digital_master_reverb            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_digital_master_reverb@16");
	lpfn_AIL_minimum_sample_buffer_size       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_minimum_sample_buffer_size@12");
	lpfn_AIL_sample_buffer_ready              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sample_buffer_ready@4");
	lpfn_AIL_load_sample_buffer               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_load_sample_buffer@16");
	lpfn_AIL_sample_buffer_info               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sample_buffer_info@20");
	lpfn_AIL_sample_granularity               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sample_granularity@4");
	lpfn_AIL_set_sample_position              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sample_position@8");
	lpfn_AIL_sample_position                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sample_position@4");
	lpfn_AIL_register_SOB_callback            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_register_SOB_callback@8");
	lpfn_AIL_register_EOB_callback            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_register_EOB_callback@8");
	lpfn_AIL_register_EOS_callback            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_register_EOS_callback@8");
	lpfn_AIL_register_EOF_callback            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_register_EOF_callback@8");
	lpfn_AIL_set_sample_user_data             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sample_user_data@12");
	lpfn_AIL_sample_user_data                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sample_user_data@8");
	lpfn_AIL_active_sample_count              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_active_sample_count@4");
	lpfn_AIL_digital_configuration            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_digital_configuration@16");
	lpfn_AIL_get_DirectSound_info             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_get_DirectSound_info@12");
	lpfn_AIL_set_DirectSound_HWND             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_DirectSound_HWND@8");
	lpfn_AIL_open_XMIDI_driver                = (DBG_VOID)GetProcAddress(hDBG, "_AIL_open_XMIDI_driver@4");
	lpfn_AIL_close_XMIDI_driver               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_close_XMIDI_driver@4");
	lpfn_AIL_midiOutOpen                      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_midiOutOpen@12");
	lpfn_AIL_midiOutClose                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_midiOutClose@4");
	lpfn_AIL_MIDI_handle_release              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_MIDI_handle_release@4");
	lpfn_AIL_MIDI_handle_reacquire            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_MIDI_handle_reacquire@4");
	lpfn_AIL_allocate_sequence_handle         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_allocate_sequence_handle@4");
	lpfn_AIL_release_sequence_handle          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_release_sequence_handle@4");
	lpfn_AIL_init_sequence                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_init_sequence@12");
	lpfn_AIL_start_sequence                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_start_sequence@4");
	lpfn_AIL_stop_sequence                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stop_sequence@4");
	lpfn_AIL_resume_sequence                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_resume_sequence@4");
	lpfn_AIL_end_sequence                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_end_sequence@4");
	lpfn_AIL_set_sequence_tempo               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sequence_tempo@12");
	lpfn_AIL_set_sequence_volume              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sequence_volume@12");
	lpfn_AIL_set_sequence_loop_count          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sequence_loop_count@8");
	lpfn_AIL_sequence_status                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sequence_status@4");
	lpfn_AIL_sequence_tempo                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sequence_tempo@4");
	lpfn_AIL_sequence_volume                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sequence_volume@4");
	lpfn_AIL_sequence_loop_count              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sequence_loop_count@4");
	lpfn_AIL_set_XMIDI_master_volume          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_XMIDI_master_volume@8");
	lpfn_AIL_XMIDI_master_volume              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_XMIDI_master_volume@4");
	lpfn_AIL_active_sequence_count            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_active_sequence_count@4");
	lpfn_AIL_controller_value                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_controller_value@12");
	lpfn_AIL_channel_notes                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_channel_notes@8");
	lpfn_AIL_sequence_position                = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sequence_position@12");
	lpfn_AIL_branch_index                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_branch_index@8");
	lpfn_AIL_register_prefix_callback         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_register_prefix_callback@8");
	lpfn_AIL_register_trigger_callback        = (DBG_VOID)GetProcAddress(hDBG, "_AIL_register_trigger_callback@8");
	lpfn_AIL_register_sequence_callback       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_register_sequence_callback@8");
	lpfn_AIL_register_beat_callback           = (DBG_VOID)GetProcAddress(hDBG, "_AIL_register_beat_callback@8");
	lpfn_AIL_register_event_callback          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_register_event_callback@8");
	lpfn_AIL_register_timbre_callback         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_register_timbre_callback@8");
	lpfn_AIL_set_sequence_user_data           = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sequence_user_data@12");
	lpfn_AIL_sequence_user_data               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sequence_user_data@8");
	lpfn_AIL_register_ICA_array               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_register_ICA_array@8");
	lpfn_AIL_lock_channel                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_lock_channel@4");
	lpfn_AIL_release_channel                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_release_channel@8");
	lpfn_AIL_map_sequence_channel             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_map_sequence_channel@12");
	lpfn_AIL_true_sequence_channel            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_true_sequence_channel@8");
	lpfn_AIL_send_channel_voice_message       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_send_channel_voice_message@20");
	lpfn_AIL_send_sysex_message               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_send_sysex_message@8");
	lpfn_AIL_create_wave_synthesizer          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_create_wave_synthesizer@16");
	lpfn_AIL_destroy_wave_synthesizer         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_destroy_wave_synthesizer@4");
	lpfn_AIL_file_error                       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_file_error@0");
	lpfn_AIL_file_size                        = (DBG_VOID)GetProcAddress(hDBG, "_AIL_file_size@4");
	lpfn_AIL_file_read                        = (DBG_VOID)GetProcAddress(hDBG, "_AIL_file_read@8");
	lpfn_AIL_file_write                       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_file_write@12");
	lpfn_AIL_WAV_file_write                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_WAV_file_write@20");
	lpfn_AIL_serve                            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_serve@0");
	lpfn_AIL_redbook_open                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_open@4");
	lpfn_AIL_redbook_open_drive               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_open_drive@4");
	lpfn_AIL_redbook_close                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_close@4");
	lpfn_AIL_redbook_eject                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_eject@4");
	lpfn_AIL_redbook_retract                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_retract@4");
	lpfn_AIL_redbook_status                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_status@4");
	lpfn_AIL_redbook_tracks                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_tracks@4");
	lpfn_AIL_redbook_track                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_track@4");
	lpfn_AIL_redbook_track_info               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_track_info@16");
	lpfn_AIL_redbook_id                       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_id@4");
	lpfn_AIL_redbook_position                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_position@4");
	lpfn_AIL_redbook_play                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_play@12");
	lpfn_AIL_redbook_stop                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_stop@4");
	lpfn_AIL_redbook_pause                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_pause@4");
	lpfn_AIL_redbook_resume                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_resume@4");
	lpfn_AIL_redbook_volume_level             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_volume_level@4");
	lpfn_AIL_redbook_set_volume_level         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_redbook_set_volume_level@8");
	lpfn_AIL_quick_startup                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_startup@20");
	lpfn_AIL_quick_shutdown                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_shutdown@0");
	lpfn_AIL_quick_handles                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_handles@12");
	lpfn_AIL_quick_load                       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_load@4");
	lpfn_AIL_quick_load_mem                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_load_mem@8");
	lpfn_AIL_quick_copy                       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_copy@4");
	lpfn_AIL_quick_unload                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_unload@4");
	lpfn_AIL_quick_play                       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_play@8");
	lpfn_AIL_quick_halt                       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_halt@4");
	lpfn_AIL_quick_status                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_status@4");
	lpfn_AIL_quick_load_and_play              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_load_and_play@12");
	lpfn_AIL_quick_set_speed                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_set_speed@8");
	lpfn_AIL_quick_set_volume                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_set_volume@12");
	lpfn_AIL_quick_set_reverb_levels          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_set_reverb_levels@12");
	lpfn_AIL_quick_set_low_pass_cut_off       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_set_low_pass_cut_off@8");
	lpfn_AIL_open_stream                      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_open_stream@12");
	lpfn_AIL_close_stream                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_close_stream@4");
	lpfn_AIL_service_stream                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_service_stream@8");
	lpfn_AIL_start_stream                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_start_stream@4");
	lpfn_AIL_pause_stream                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_pause_stream@8");
	lpfn_AIL_set_stream_volume_pan            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_stream_volume_pan@12");
	lpfn_AIL_set_stream_volume_levels         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_stream_volume_levels@12");
	lpfn_AIL_set_stream_reverb_levels         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_stream_reverb_levels@12");
	lpfn_AIL_set_stream_low_pass_cut_off      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_stream_low_pass_cut_off@8");
	lpfn_AIL_stream_volume_pan                = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stream_volume_pan@12");
	lpfn_AIL_stream_volume_levels             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stream_volume_levels@12");
	lpfn_AIL_stream_reverb_levels             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stream_reverb_levels@12");
	lpfn_AIL_stream_low_pass_cut_off          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stream_low_pass_cut_off@4");
	lpfn_AIL_set_stream_playback_rate         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_stream_playback_rate@8");
	lpfn_AIL_stream_playback_rate             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stream_playback_rate@4");
	lpfn_AIL_stream_loop_count                = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stream_loop_count@4");
	lpfn_AIL_set_stream_loop_block            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_stream_loop_block@12");
	lpfn_AIL_set_stream_loop_count            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_stream_loop_count@8");
	lpfn_AIL_stream_status                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stream_status@4");
	lpfn_AIL_set_stream_position              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_stream_position@8");
	lpfn_AIL_stream_position                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stream_position@4");
	lpfn_AIL_stream_info                      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stream_info@20");
	lpfn_AIL_register_stream_callback         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_register_stream_callback@8");
	lpfn_AIL_auto_service_stream              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_auto_service_stream@8");
	lpfn_AIL_set_stream_user_data             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_stream_user_data@12");
	lpfn_AIL_stream_user_data                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stream_user_data@8");
	lpfn_AIL_DLS_open                         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_DLS_open@28");
	lpfn_AIL_DLS_close                        = (DBG_VOID)GetProcAddress(hDBG, "_AIL_DLS_close@8");
	lpfn_AIL_DLS_load_file                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_DLS_load_file@12");
	lpfn_AIL_DLS_load_memory                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_DLS_load_memory@12");
	lpfn_AIL_DLS_unload                       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_DLS_unload@8");
	lpfn_AIL_DLS_compact                      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_DLS_compact@4");
	lpfn_AIL_DLS_set_reverb_levels            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_DLS_set_reverb_levels@12");
	lpfn_AIL_DLS_get_reverb_levels            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_DLS_get_reverb_levels@12");
	lpfn_AIL_DLS_get_info                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_DLS_get_info@12");
	lpfn_AIL_set_sequence_ms_position         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sequence_ms_position@8");
	lpfn_AIL_sequence_ms_position             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sequence_ms_position@12");
	lpfn_AIL_sample_ms_position               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_sample_ms_position@12");
	lpfn_AIL_set_sample_ms_position           = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_sample_ms_position@8");
	lpfn_AIL_stream_ms_position               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stream_ms_position@12");
	lpfn_AIL_set_stream_ms_position           = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_stream_ms_position@8");
	lpfn_AIL_quick_set_ms_position            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_set_ms_position@8");
	lpfn_AIL_quick_ms_position                = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_ms_position@4");
	lpfn_AIL_quick_ms_length                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_ms_length@4");
	lpfn_AIL_quick_type                       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_quick_type@4");
	lpfn_AIL_MIDI_to_XMI                      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_MIDI_to_XMI@20");
	lpfn_AIL_compress_ADPCM                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_compress_ADPCM@12");
	lpfn_AIL_decompress_ADPCM                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_decompress_ADPCM@12");
	lpfn_AIL_WAV_info                         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_WAV_info@8");
	lpfn_AIL_file_type                        = (DBG_VOID)GetProcAddress(hDBG, "_AIL_file_type@8");
	lpfn_AIL_find_DLS                         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_find_DLS@24");
	lpfn_AIL_extract_DLS                      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_extract_DLS@28");
	lpfn_AIL_primary_digital_driver           = (DBG_VOID)GetProcAddress(hDBG, "_AIL_primary_digital_driver@4");
	lpfn_AIL_enumerate_filters                = (DBG_VOID)GetProcAddress(hDBG, "_AIL_enumerate_filters@12");
	lpfn_AIL_open_filter                      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_open_filter@8");
	lpfn_AIL_close_filter                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_close_filter@4");
	lpfn_AIL_enumerate_filter_attributes      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_enumerate_filter_attributes@12");
	lpfn_AIL_enumerate_filter_sample_attribute= (DBG_VOID)GetProcAddress(hDBG, "_AIL_enumerate_filter_sample_attributes@12");
	lpfn_AIL_filter_attribute                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_filter_attribute@12");
	lpfn_AIL_filter_sample_attribute          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_filter_sample_attribute@12");
	lpfn_AIL_filter_stream_attribute          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_filter_stream_attribute@12");
	lpfn_AIL_filter_DLS_attribute             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_filter_DLS_attribute@12");
	lpfn_AIL_set_filter_preference            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_filter_preference@12");
	lpfn_AIL_set_filter_sample_preference     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_filter_sample_preference@12");
	lpfn_AIL_set_filter_stream_preference     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_filter_stream_preference@12");
	lpfn_AIL_set_filter_DLS_preference        = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_filter_DLS_preference@12");
	lpfn_AIL_enumerate_3D_providers           = (DBG_VOID)GetProcAddress(hDBG, "_AIL_enumerate_3D_providers@12");
	lpfn_AIL_open_3D_provider                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_open_3D_provider@4");
	lpfn_AIL_close_3D_provider                = (DBG_VOID)GetProcAddress(hDBG, "_AIL_close_3D_provider@4");
	lpfn_AIL_enumerate_3D_provider_attributes = (DBG_VOID)GetProcAddress(hDBG, "_AIL_enumerate_3D_provider_attributes@12");
	lpfn_AIL_enumerate_3D_sample_attributes   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_enumerate_3D_sample_attributes@12");
	lpfn_AIL_3D_provider_attribute            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_provider_attribute@12");
	lpfn_AIL_3D_sample_attribute              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_sample_attribute@12");
	lpfn_AIL_set_3D_provider_preference       = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_provider_preference@12");
	lpfn_AIL_set_3D_sample_preference         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_sample_preference@12");
	lpfn_AIL_allocate_3D_sample_handle        = (DBG_VOID)GetProcAddress(hDBG, "_AIL_allocate_3D_sample_handle@4");
	lpfn_AIL_release_3D_sample_handle         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_release_3D_sample_handle@4");
	lpfn_AIL_start_3D_sample                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_start_3D_sample@4");
	lpfn_AIL_stop_3D_sample                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_stop_3D_sample@4");
	lpfn_AIL_resume_3D_sample                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_resume_3D_sample@4");
	lpfn_AIL_end_3D_sample                    = (DBG_VOID)GetProcAddress(hDBG, "_AIL_end_3D_sample@4");
	lpfn_AIL_set_3D_sample_info               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_sample_info@8");
	lpfn_AIL_set_3D_sample_file               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_sample_file@8");
	lpfn_AIL_set_3D_sample_volume             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_sample_volume@8");
	lpfn_AIL_set_3D_sample_playback_rate      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_sample_playback_rate@8");
	lpfn_AIL_set_3D_sample_offset             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_sample_offset@8");
	lpfn_AIL_set_3D_sample_loop_count         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_sample_loop_count@8");
	lpfn_AIL_set_3D_sample_loop_block         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_sample_loop_block@12");
	lpfn_AIL_set_3D_sample_obstruction        = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_sample_obstruction@8");
	lpfn_AIL_set_3D_sample_exclusion          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_sample_exclusion@8");
	lpfn_AIL_set_3D_sample_occlusion          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_sample_occlusion@8");
	lpfn_AIL_set_3D_sample_cone               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_sample_cone@16");
	lpfn_AIL_set_3D_sample_effects_level      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_sample_effects_level@8");
	lpfn_AIL_register_3D_EOS_callback         = (DBG_VOID)GetProcAddress(hDBG, "_AIL_register_3D_EOS_callback@8");
	lpfn_AIL_3D_sample_obstruction            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_sample_obstruction@4");
	lpfn_AIL_3D_sample_exclusion              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_sample_exclusion@4");
	lpfn_AIL_3D_sample_occlusion              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_sample_occlusion@4");
	lpfn_AIL_3D_sample_cone                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_sample_cone@16");
	lpfn_AIL_3D_sample_effects_level          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_sample_effects_level@4");
	lpfn_AIL_3D_sample_status                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_sample_status@4");
	lpfn_AIL_3D_sample_volume                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_sample_volume@4");
	lpfn_AIL_3D_sample_playback_rate          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_sample_playback_rate@4");
	lpfn_AIL_3D_sample_offset                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_sample_offset@4");
	lpfn_AIL_3D_sample_length                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_sample_length@4");
	lpfn_AIL_3D_sample_loop_count             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_sample_loop_count@4");
	lpfn_AIL_set_3D_sample_distances          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_sample_distances@12");
	lpfn_AIL_3D_sample_distances              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_sample_distances@12");
	lpfn_AIL_set_3D_user_data                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_user_data@12");
	lpfn_AIL_3D_user_data                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_user_data@8");
	lpfn_AIL_active_3D_sample_count           = (DBG_VOID)GetProcAddress(hDBG, "_AIL_active_3D_sample_count@4");
	lpfn_AIL_3D_room_type                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_room_type@4");
	lpfn_AIL_set_3D_room_type                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_room_type@8");
	lpfn_AIL_3D_speaker_type                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_speaker_type@4");
	lpfn_AIL_set_3D_speaker_type              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_speaker_type@8");
	lpfn_AIL_3D_rolloff_factor                = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_rolloff_factor@4");
	lpfn_AIL_set_3D_rolloff_factor            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_rolloff_factor@8");
	lpfn_AIL_3D_doppler_factor                = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_doppler_factor@4");
	lpfn_AIL_set_3D_doppler_factor            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_doppler_factor@8");
	lpfn_AIL_3D_distance_factor               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_distance_factor@4");
	lpfn_AIL_set_3D_distance_factor           = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_distance_factor@8");
	lpfn_AIL_open_3D_listener                 = (DBG_VOID)GetProcAddress(hDBG, "_AIL_open_3D_listener@4");
	lpfn_AIL_close_3D_listener                = (DBG_VOID)GetProcAddress(hDBG, "_AIL_close_3D_listener@4");
	lpfn_AIL_open_3D_object                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_open_3D_object@4");
	lpfn_AIL_close_3D_object                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_close_3D_object@4");
	lpfn_AIL_set_3D_position                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_position@16");
	lpfn_AIL_set_3D_velocity                  = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_velocity@20");
	lpfn_AIL_set_3D_velocity_vector           = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_velocity_vector@16");
	lpfn_AIL_set_3D_orientation               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_3D_orientation@28");
	lpfn_AIL_3D_position                      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_position@16");
	lpfn_AIL_3D_velocity                      = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_velocity@16");
	lpfn_AIL_3D_orientation                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_3D_orientation@28");
	lpfn_AIL_update_3D_position               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_update_3D_position@8");
	lpfn_AIL_auto_update_3D_position          = (DBG_VOID)GetProcAddress(hDBG, "_AIL_auto_update_3D_position@8");
	lpfn_AIL_size_processed_digital_audio     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_size_processed_digital_audio@16");
	lpfn_AIL_process_digital_audio            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_process_digital_audio@24");
	lpfn_AIL_merge_DLS_with_XMI               = (DBG_VOID)GetProcAddress(hDBG, "_AIL_merge_DLS_with_XMI@16");
	lpfn_AIL_compress_DLS                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_compress_DLS@20");
	lpfn_AIL_filter_DLS_with_XMI              = (DBG_VOID)GetProcAddress(hDBG, "_AIL_filter_DLS_with_XMI@24");
	lpfn_AIL_compress_ASI                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_compress_ASI@20");
	lpfn_AIL_decompress_ASI                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_decompress_ASI@24");
	lpfn_AIL_request_EOB_ASI_reset            = (DBG_VOID)GetProcAddress(hDBG, "_AIL_request_EOB_ASI_reset@8");
	lpfn_AIL_set_redist_directory             = (DBG_VOID)GetProcAddress(hDBG, "_AIL_set_redist_directory@4");
	lpfn_MIX_RIB_MAIN                         = (DBG_VOID)GetProcAddress(hDBG, "_MIX_RIB_MAIN@8");
	lpfn_AIL_mem_use_malloc                   = (DBG_VOID)GetProcAddress(hDBG, "_AIL_mem_use_malloc@4");
	lpfn_AIL_mem_use_free                     = (DBG_VOID)GetProcAddress(hDBG, "_AIL_mem_use_free@4");
	lpfnAIL_sprintf                           = (DBG_VOID)GetProcAddress(hDBG, "AIL_sprintf");
	lpfnDLSMSSOpen                            = (DBG_VOID)GetProcAddress(hDBG, "DLSMSSOpen");
	lpfnDLSClose                              = (DBG_VOID)GetProcAddress(hDBG, "DLSClose");
	lpfnDLSLoadFile                           = (DBG_VOID)GetProcAddress(hDBG, "DLSLoadFile");
	lpfnDLSLoadMemFile                        = (DBG_VOID)GetProcAddress(hDBG, "DLSLoadMemFile");
	lpfnDLSGetInfo                            = (DBG_VOID)GetProcAddress(hDBG, "DLSGetInfo");
	lpfnDLSCompactMemory                      = (DBG_VOID)GetProcAddress(hDBG, "DLSCompactMemory");
	lpfnDLSUnloadAll                          = (DBG_VOID)GetProcAddress(hDBG, "DLSUnloadAll");
	lpfnDLSUnloadFile                         = (DBG_VOID)GetProcAddress(hDBG, "DLSUnloadFile");
	lpfnDLSSetAttribute                       = (DBG_VOID)GetProcAddress(hDBG, "DLSSetAttribute");
	lpfn_DLSMSSGetCPU                         = (DBG_VOID)GetProcAddress(hDBG, "_DLSMSSGetCPU@4");


	if (!lpfn_AIL_get_preference ||
		!lpfn_AIL_lock ||
		!lpfn_AIL_unlock ||
		!lpfn_AIL_lock_mutex ||
		!lpfn_AIL_unlock_mutex ||
		!lpfn_AIL_get_timer_highest_delay ||
		!lpfn_DllMain ||
		!lpfn_RIB_load_static_provider_library ||
		!lpfnRIB_alloc_provider_handle ||
		!lpfnRIB_free_provider_handle ||
		!lpfnRIB_load_provider_library ||
		!lpfnRIB_free_provider_library ||
		!lpfnRIB_register_interface ||
		!lpfnRIB_request_interface ||
		!lpfnRIB_request_interface_entry ||
		!lpfnRIB_unregister_interface ||
		!lpfnRIB_enumerate_interface ||
		!lpfn_RIB_enumerate_providers ||
		!lpfnRIB_type_string ||
		!lpfnRIB_find_file_provider ||
		!lpfn_RIB_find_files_provider ||
		!lpfn_RIB_find_file_dec_provider ||
		!lpfn_RIB_find_provider ||
		!lpfn_RIB_load_application_providers ||
		!lpfn_RIB_set_provider_user_data ||
		!lpfn_RIB_provider_user_data ||
		!lpfn_RIB_set_provider_system_data ||
		!lpfn_RIB_provider_system_data ||
		!lpfnRIB_error ||
		!lpfn_AIL_set_file_async_callbacks ||
		!lpfn_AIL_set_file_callbacks ||
		!lpfn_AIL_list_DLS ||
		!lpfn_AIL_list_MIDI ||
		!lpfnstream_background ||
		!lpfn_AIL_ms_count ||
		!lpfn_AIL_us_count ||
		!lpfn_AIL_MMX_available ||
		!lpfnAIL_debug_printf ||
		!lpfn_AIL_startup ||
		!lpfn_AIL_shutdown ||
		!lpfn_AIL_HWND ||
		!lpfn_AIL_mem_alloc_lock ||
		!lpfn_AIL_mem_free_lock ||
		!lpfn_AIL_set_preference ||
		!lpfn_AIL_last_error ||
		!lpfn_AIL_set_error ||
		!lpfn_AIL_delay ||
		!lpfn_AIL_background ||
		!lpfn_AIL_register_timer ||
		!lpfn_AIL_set_timer_user ||
		!lpfn_AIL_set_timer_period ||
		!lpfn_AIL_set_timer_frequency ||
		!lpfn_AIL_set_timer_divisor ||
		!lpfn_AIL_start_timer ||
		!lpfn_AIL_start_all_timers ||
		!lpfn_AIL_stop_timer ||
		!lpfn_AIL_stop_all_timers ||
		!lpfn_AIL_release_timer_handle ||
		!lpfn_AIL_release_all_timers ||
		!lpfn_AIL_open_digital_driver ||
		!lpfn_AIL_close_digital_driver ||
		!lpfn_AIL_waveOutOpen ||
		!lpfn_AIL_waveOutClose ||
		!lpfn_AIL_digital_handle_release ||
		!lpfn_AIL_digital_handle_reacquire ||
		!lpfn_AIL_open_input ||
		!lpfn_AIL_close_input ||
		!lpfn_AIL_get_input_info ||
		!lpfn_AIL_set_input_state ||
		!lpfn_AIL_digital_CPU_percent ||
		!lpfn_AIL_digital_latency ||
		!lpfn_AIL_allocate_sample_handle ||
		!lpfn_AIL_allocate_file_sample ||
		!lpfn_AIL_release_sample_handle ||
		!lpfn_AIL_init_sample ||
		!lpfn_AIL_set_sample_file ||
		!lpfn_AIL_set_named_sample_file ||
		!lpfn_AIL_set_sample_processor ||
		!lpfn_AIL_set_stream_processor ||
		!lpfn_AIL_set_DLS_processor ||
		!lpfn_AIL_set_digital_driver_processor ||
		!lpfn_AIL_set_sample_address ||
		!lpfn_AIL_set_sample_type ||
		!lpfn_AIL_set_sample_adpcm_block_size ||
		!lpfn_AIL_start_sample ||
		!lpfn_AIL_stop_sample ||
		!lpfn_AIL_resume_sample ||
		!lpfn_AIL_end_sample ||
		!lpfn_AIL_set_sample_playback_rate ||
		!lpfn_AIL_set_sample_volume_pan ||
		!lpfn_AIL_set_sample_volume_levels ||
		!lpfn_AIL_set_sample_reverb_levels ||
		!lpfn_AIL_set_sample_low_pass_cut_off ||
		!lpfn_AIL_set_sample_loop_count ||
		!lpfn_AIL_set_sample_loop_block ||
		!lpfn_AIL_sample_status ||
		!lpfn_AIL_sample_playback_rate ||
		!lpfn_AIL_sample_volume_pan ||
		!lpfn_AIL_sample_volume_levels ||
		!lpfn_AIL_sample_reverb_levels ||
		!lpfn_AIL_sample_low_pass_cut_off ||
		!lpfn_AIL_sample_loop_count ||
		!lpfn_AIL_set_digital_master_volume_level ||
		!lpfn_AIL_digital_master_volume_level ||
		!lpfn_AIL_set_digital_master_reverb_levels ||
		!lpfn_AIL_set_digital_master_room_type ||
		!lpfn_AIL_digital_master_reverb_levels ||
		!lpfn_AIL_set_digital_master_reverb ||
		!lpfn_AIL_digital_master_reverb ||
		!lpfn_AIL_minimum_sample_buffer_size ||
		!lpfn_AIL_sample_buffer_ready ||
		!lpfn_AIL_load_sample_buffer ||
		!lpfn_AIL_sample_buffer_info ||
		!lpfn_AIL_sample_granularity ||
		!lpfn_AIL_set_sample_position ||
		!lpfn_AIL_sample_position ||
		!lpfn_AIL_register_SOB_callback ||
		!lpfn_AIL_register_EOB_callback ||
		!lpfn_AIL_register_EOS_callback ||
		!lpfn_AIL_register_EOF_callback ||
		!lpfn_AIL_set_sample_user_data ||
		!lpfn_AIL_sample_user_data ||
		!lpfn_AIL_active_sample_count ||
		!lpfn_AIL_digital_configuration ||
		!lpfn_AIL_get_DirectSound_info ||
		!lpfn_AIL_set_DirectSound_HWND ||
		!lpfn_AIL_open_XMIDI_driver ||
		!lpfn_AIL_close_XMIDI_driver ||
		!lpfn_AIL_midiOutOpen ||
		!lpfn_AIL_midiOutClose ||
		!lpfn_AIL_MIDI_handle_release ||
		!lpfn_AIL_MIDI_handle_reacquire ||
		!lpfn_AIL_allocate_sequence_handle ||
		!lpfn_AIL_release_sequence_handle ||
		!lpfn_AIL_init_sequence ||
		!lpfn_AIL_start_sequence ||
		!lpfn_AIL_stop_sequence ||
		!lpfn_AIL_resume_sequence ||
		!lpfn_AIL_end_sequence ||
		!lpfn_AIL_set_sequence_tempo ||
		!lpfn_AIL_set_sequence_volume ||
		!lpfn_AIL_set_sequence_loop_count ||
		!lpfn_AIL_sequence_status ||
		!lpfn_AIL_sequence_tempo ||
		!lpfn_AIL_sequence_volume ||
		!lpfn_AIL_sequence_loop_count ||
		!lpfn_AIL_set_XMIDI_master_volume ||
		!lpfn_AIL_XMIDI_master_volume ||
		!lpfn_AIL_active_sequence_count ||
		!lpfn_AIL_controller_value ||
		!lpfn_AIL_channel_notes ||
		!lpfn_AIL_sequence_position ||
		!lpfn_AIL_branch_index ||
		!lpfn_AIL_register_prefix_callback ||
		!lpfn_AIL_register_trigger_callback ||
		!lpfn_AIL_register_sequence_callback ||
		!lpfn_AIL_register_beat_callback ||
		!lpfn_AIL_register_event_callback ||
		!lpfn_AIL_register_timbre_callback ||
		!lpfn_AIL_set_sequence_user_data ||
		!lpfn_AIL_sequence_user_data ||
		!lpfn_AIL_register_ICA_array ||
		!lpfn_AIL_lock_channel ||
		!lpfn_AIL_release_channel ||
		!lpfn_AIL_map_sequence_channel ||
		!lpfn_AIL_true_sequence_channel ||
		!lpfn_AIL_send_channel_voice_message ||
		!lpfn_AIL_send_sysex_message ||
		!lpfn_AIL_create_wave_synthesizer ||
		!lpfn_AIL_destroy_wave_synthesizer ||
		!lpfn_AIL_file_error ||
		!lpfn_AIL_file_size ||
		!lpfn_AIL_file_read ||
		!lpfn_AIL_file_write ||
		!lpfn_AIL_WAV_file_write ||
		!lpfn_AIL_serve ||
		!lpfn_AIL_redbook_open ||
		!lpfn_AIL_redbook_open_drive ||
		!lpfn_AIL_redbook_close ||
		!lpfn_AIL_redbook_eject ||
		!lpfn_AIL_redbook_retract ||
		!lpfn_AIL_redbook_status ||
		!lpfn_AIL_redbook_tracks ||
		!lpfn_AIL_redbook_track ||
		!lpfn_AIL_redbook_track_info ||
		!lpfn_AIL_redbook_id ||
		!lpfn_AIL_redbook_position ||
		!lpfn_AIL_redbook_play ||
		!lpfn_AIL_redbook_stop ||
		!lpfn_AIL_redbook_pause ||
		!lpfn_AIL_redbook_resume ||
		!lpfn_AIL_redbook_volume_level ||
		!lpfn_AIL_redbook_set_volume_level ||
		!lpfn_AIL_quick_startup ||
		!lpfn_AIL_quick_shutdown ||
		!lpfn_AIL_quick_handles ||
		!lpfn_AIL_quick_load ||
		!lpfn_AIL_quick_load_mem ||
		!lpfn_AIL_quick_copy ||
		!lpfn_AIL_quick_unload ||
		!lpfn_AIL_quick_play ||
		!lpfn_AIL_quick_halt ||
		!lpfn_AIL_quick_status ||
		!lpfn_AIL_quick_load_and_play ||
		!lpfn_AIL_quick_set_speed ||
		!lpfn_AIL_quick_set_volume ||
		!lpfn_AIL_quick_set_reverb_levels ||
		!lpfn_AIL_quick_set_low_pass_cut_off ||
		!lpfn_AIL_open_stream ||
		!lpfn_AIL_close_stream ||
		!lpfn_AIL_service_stream ||
		!lpfn_AIL_start_stream ||
		!lpfn_AIL_pause_stream ||
		!lpfn_AIL_set_stream_volume_pan ||
		!lpfn_AIL_set_stream_volume_levels ||
		!lpfn_AIL_set_stream_reverb_levels ||
		!lpfn_AIL_set_stream_low_pass_cut_off ||
		!lpfn_AIL_stream_volume_pan ||
		!lpfn_AIL_stream_volume_levels ||
		!lpfn_AIL_stream_reverb_levels ||
		!lpfn_AIL_stream_low_pass_cut_off ||
		!lpfn_AIL_set_stream_playback_rate ||
		!lpfn_AIL_stream_playback_rate ||
		!lpfn_AIL_stream_loop_count ||
		!lpfn_AIL_set_stream_loop_block ||
		!lpfn_AIL_set_stream_loop_count ||
		!lpfn_AIL_stream_status ||
		!lpfn_AIL_set_stream_position ||
		!lpfn_AIL_stream_position ||
		!lpfn_AIL_stream_info ||
		!lpfn_AIL_register_stream_callback ||
		!lpfn_AIL_auto_service_stream ||
		!lpfn_AIL_set_stream_user_data ||
		!lpfn_AIL_stream_user_data ||
		!lpfn_AIL_DLS_open ||
		!lpfn_AIL_DLS_close ||
		!lpfn_AIL_DLS_load_file ||
		!lpfn_AIL_DLS_load_memory ||
		!lpfn_AIL_DLS_unload ||
		!lpfn_AIL_DLS_compact ||
		!lpfn_AIL_DLS_set_reverb_levels ||
		!lpfn_AIL_DLS_get_reverb_levels ||
		!lpfn_AIL_DLS_get_info ||
		!lpfn_AIL_set_sequence_ms_position ||
		!lpfn_AIL_sequence_ms_position ||
		!lpfn_AIL_sample_ms_position ||
		!lpfn_AIL_set_sample_ms_position ||
		!lpfn_AIL_stream_ms_position ||
		!lpfn_AIL_set_stream_ms_position ||
		!lpfn_AIL_quick_set_ms_position ||
		!lpfn_AIL_quick_ms_position ||
		!lpfn_AIL_quick_ms_length ||
		!lpfn_AIL_quick_type ||
		!lpfn_AIL_MIDI_to_XMI ||
		!lpfn_AIL_compress_ADPCM ||
		!lpfn_AIL_decompress_ADPCM ||
		!lpfn_AIL_WAV_info ||
		!lpfn_AIL_file_type ||
		!lpfn_AIL_find_DLS ||
		!lpfn_AIL_extract_DLS ||
		!lpfn_AIL_primary_digital_driver ||
		!lpfn_AIL_enumerate_filters ||
		!lpfn_AIL_open_filter ||
		!lpfn_AIL_close_filter ||
		!lpfn_AIL_enumerate_filter_attributes ||
		!lpfn_AIL_enumerate_filter_sample_attribute ||
		!lpfn_AIL_filter_attribute ||
		!lpfn_AIL_filter_sample_attribute ||
		!lpfn_AIL_filter_stream_attribute ||
		!lpfn_AIL_filter_DLS_attribute ||
		!lpfn_AIL_set_filter_preference ||
		!lpfn_AIL_set_filter_sample_preference ||
		!lpfn_AIL_set_filter_stream_preference ||
		!lpfn_AIL_set_filter_DLS_preference ||
		!lpfn_AIL_enumerate_3D_providers ||
		!lpfn_AIL_open_3D_provider ||
		!lpfn_AIL_close_3D_provider ||
		!lpfn_AIL_enumerate_3D_provider_attributes ||
		!lpfn_AIL_enumerate_3D_sample_attributes ||
		!lpfn_AIL_3D_provider_attribute ||
		!lpfn_AIL_3D_sample_attribute ||
		!lpfn_AIL_set_3D_provider_preference ||
		!lpfn_AIL_set_3D_sample_preference ||
		!lpfn_AIL_allocate_3D_sample_handle ||
		!lpfn_AIL_release_3D_sample_handle ||
		!lpfn_AIL_start_3D_sample ||
		!lpfn_AIL_stop_3D_sample ||
		!lpfn_AIL_resume_3D_sample ||
		!lpfn_AIL_end_3D_sample ||
		!lpfn_AIL_set_3D_sample_info ||
		!lpfn_AIL_set_3D_sample_file ||
		!lpfn_AIL_set_3D_sample_volume ||
		!lpfn_AIL_set_3D_sample_playback_rate ||
		!lpfn_AIL_set_3D_sample_offset ||
		!lpfn_AIL_set_3D_sample_loop_count ||
		!lpfn_AIL_set_3D_sample_loop_block ||
		!lpfn_AIL_set_3D_sample_obstruction ||
		!lpfn_AIL_set_3D_sample_exclusion ||
		!lpfn_AIL_set_3D_sample_occlusion ||
		!lpfn_AIL_set_3D_sample_cone ||
		!lpfn_AIL_set_3D_sample_effects_level ||
		!lpfn_AIL_register_3D_EOS_callback ||
		!lpfn_AIL_3D_sample_obstruction ||
		!lpfn_AIL_3D_sample_exclusion ||
		!lpfn_AIL_3D_sample_occlusion ||
		!lpfn_AIL_3D_sample_cone ||
		!lpfn_AIL_3D_sample_effects_level ||
		!lpfn_AIL_3D_sample_status ||
		!lpfn_AIL_3D_sample_volume ||
		!lpfn_AIL_3D_sample_playback_rate ||
		!lpfn_AIL_3D_sample_offset ||
		!lpfn_AIL_3D_sample_length ||
		!lpfn_AIL_3D_sample_loop_count ||
		!lpfn_AIL_set_3D_sample_distances ||
		!lpfn_AIL_3D_sample_distances ||
		!lpfn_AIL_set_3D_user_data ||
		!lpfn_AIL_3D_user_data ||
		!lpfn_AIL_active_3D_sample_count ||
		!lpfn_AIL_3D_room_type ||
		!lpfn_AIL_set_3D_room_type ||
		!lpfn_AIL_3D_speaker_type ||
		!lpfn_AIL_set_3D_speaker_type ||
		!lpfn_AIL_3D_rolloff_factor ||
		!lpfn_AIL_set_3D_rolloff_factor ||
		!lpfn_AIL_3D_doppler_factor ||
		!lpfn_AIL_set_3D_doppler_factor ||
		!lpfn_AIL_3D_distance_factor ||
		!lpfn_AIL_set_3D_distance_factor ||
		!lpfn_AIL_open_3D_listener ||
		!lpfn_AIL_close_3D_listener ||
		!lpfn_AIL_open_3D_object ||
		!lpfn_AIL_close_3D_object ||
		!lpfn_AIL_set_3D_position ||
		!lpfn_AIL_set_3D_velocity ||
		!lpfn_AIL_set_3D_velocity_vector ||
		!lpfn_AIL_set_3D_orientation ||
		!lpfn_AIL_3D_position ||
		!lpfn_AIL_3D_velocity ||
		!lpfn_AIL_3D_orientation ||
		!lpfn_AIL_update_3D_position ||
		!lpfn_AIL_auto_update_3D_position ||
		!lpfn_AIL_size_processed_digital_audio ||
		!lpfn_AIL_process_digital_audio ||
		!lpfn_AIL_merge_DLS_with_XMI ||
		!lpfn_AIL_compress_DLS ||
		!lpfn_AIL_filter_DLS_with_XMI ||
		!lpfn_AIL_compress_ASI ||
		!lpfn_AIL_decompress_ASI ||
		!lpfn_AIL_request_EOB_ASI_reset ||
		!lpfn_AIL_set_redist_directory ||
		!lpfn_MIX_RIB_MAIN ||
		!lpfn_AIL_mem_use_malloc ||
		!lpfn_AIL_mem_use_free ||
		!lpfnAIL_sprintf ||
		!lpfnDLSMSSOpen ||
		!lpfnDLSClose ||
		!lpfnDLSLoadFile ||
		!lpfnDLSLoadMemFile ||
		!lpfnDLSGetInfo ||
		!lpfnDLSCompactMemory ||
		!lpfnDLSUnloadAll ||
		!lpfnDLSUnloadFile ||
		!lpfnDLSSetAttribute ||
		!lpfn_DLSMSSGetCPU)
	{
		WriteLog("-- Mss32.dll Export Table Log Start --\n");
		WriteLog("_AIL_get_preference                   %x\n", lpfn_AIL_get_preference);
		WriteLog("_AIL_lock                             %x\n", lpfn_AIL_lock);
		WriteLog("_AIL_unlock                           %x\n", lpfn_AIL_unlock);
		WriteLog("_AIL_lock_mutex                       %x\n", lpfn_AIL_lock_mutex);
		WriteLog("_AIL_unlock_mutex                     %x\n", lpfn_AIL_unlock_mutex);
		WriteLog("_AIL_get_timer_highest_delay          %x\n", lpfn_AIL_get_timer_highest_delay);
		WriteLog("_DllMain                              %x\n", lpfn_DllMain);
		WriteLog("_RIB_load_static_provider_library     %x\n", lpfn_RIB_load_static_provider_library);
		WriteLog("RIB_alloc_provider_handle             %x\n", lpfnRIB_alloc_provider_handle);
		WriteLog("RIB_free_provider_handle              %x\n", lpfnRIB_free_provider_handle);
		WriteLog("RIB_load_provider_library             %x\n", lpfnRIB_load_provider_library);
		WriteLog("RIB_free_provider_library             %x\n", lpfnRIB_free_provider_library);
		WriteLog("RIB_register_interface                %x\n", lpfnRIB_register_interface);
		WriteLog("RIB_request_interface                 %x\n", lpfnRIB_request_interface);
		WriteLog("RIB_request_interface_entry           %x\n", lpfnRIB_request_interface_entry);
		WriteLog("RIB_unregister_interface              %x\n", lpfnRIB_unregister_interface);
		WriteLog("RIB_enumerate_interface               %x\n", lpfnRIB_enumerate_interface);
		WriteLog("_RIB_enumerate_providers              %x\n", lpfn_RIB_enumerate_providers);
		WriteLog("RIB_type_string                       %x\n", lpfnRIB_type_string);
		WriteLog("RIB_find_file_provider                %x\n", lpfnRIB_find_file_provider);
		WriteLog("_RIB_find_files_provider              %x\n", lpfn_RIB_find_files_provider);
		WriteLog("_RIB_find_file_dec_provider           %x\n", lpfn_RIB_find_file_dec_provider);
		WriteLog("_RIB_find_provider                    %x\n", lpfn_RIB_find_provider);
		WriteLog("_RIB_load_application_providers       %x\n", lpfn_RIB_load_application_providers);
		WriteLog("_RIB_set_provider_user_data           %x\n", lpfn_RIB_set_provider_user_data);
		WriteLog("_RIB_provider_user_data               %x\n", lpfn_RIB_provider_user_data);
		WriteLog("_RIB_set_provider_system_data         %x\n", lpfn_RIB_set_provider_system_data);
		WriteLog("_RIB_provider_system_data             %x\n", lpfn_RIB_provider_system_data);
		WriteLog("RIB_error                             %x\n", lpfnRIB_error);
		WriteLog("_AIL_set_file_async_callbacks         %x\n", lpfn_AIL_set_file_async_callbacks);
		WriteLog("_AIL_set_file_callbacks               %x\n", lpfn_AIL_set_file_callbacks);
		WriteLog("_AIL_list_DLS                         %x\n", lpfn_AIL_list_DLS);
		WriteLog("_AIL_list_MIDI                        %x\n", lpfn_AIL_list_MIDI);
		WriteLog("stream_background                     %x\n", lpfnstream_background);
		WriteLog("_AIL_ms_count                         %x\n", lpfn_AIL_ms_count);
		WriteLog("_AIL_us_count                         %x\n", lpfn_AIL_us_count);
		WriteLog("_AIL_MMX_available                    %x\n", lpfn_AIL_MMX_available);
		WriteLog("AIL_debug_printf                      %x\n", lpfnAIL_debug_printf);
		WriteLog("_AIL_startup                          %x\n", lpfn_AIL_startup);
		WriteLog("_AIL_shutdown                         %x\n", lpfn_AIL_shutdown);
		WriteLog("_AIL_HWND                             %x\n", lpfn_AIL_HWND);
		WriteLog("_AIL_mem_alloc_lock                   %x\n", lpfn_AIL_mem_alloc_lock);
		WriteLog("_AIL_mem_free_lock                    %x\n", lpfn_AIL_mem_free_lock);
		WriteLog("_AIL_set_preference                   %x\n", lpfn_AIL_set_preference);
		WriteLog("_AIL_last_error                       %x\n", lpfn_AIL_last_error);
		WriteLog("_AIL_set_error                        %x\n", lpfn_AIL_set_error);
		WriteLog("_AIL_delay                            %x\n", lpfn_AIL_delay);
		WriteLog("_AIL_background                       %x\n", lpfn_AIL_background);
		WriteLog("_AIL_register_timer                   %x\n", lpfn_AIL_register_timer);
		WriteLog("_AIL_set_timer_user                   %x\n", lpfn_AIL_set_timer_user);
		WriteLog("_AIL_set_timer_period                 %x\n", lpfn_AIL_set_timer_period);
		WriteLog("_AIL_set_timer_frequency              %x\n", lpfn_AIL_set_timer_frequency);
		WriteLog("_AIL_set_timer_divisor                %x\n", lpfn_AIL_set_timer_divisor);
		WriteLog("_AIL_start_timer                      %x\n", lpfn_AIL_start_timer);
		WriteLog("_AIL_start_all_timers                 %x\n", lpfn_AIL_start_all_timers);
		WriteLog("_AIL_stop_timer                       %x\n", lpfn_AIL_stop_timer);
		WriteLog("_AIL_stop_all_timers                  %x\n", lpfn_AIL_stop_all_timers);
		WriteLog("_AIL_release_timer_handle             %x\n", lpfn_AIL_release_timer_handle);
		WriteLog("_AIL_release_all_timers               %x\n", lpfn_AIL_release_all_timers);
		WriteLog("_AIL_open_digital_driver              %x\n", lpfn_AIL_open_digital_driver);
		WriteLog("_AIL_close_digital_driver             %x\n", lpfn_AIL_close_digital_driver);
		WriteLog("_AIL_waveOutOpen                      %x\n", lpfn_AIL_waveOutOpen);
		WriteLog("_AIL_waveOutClose                     %x\n", lpfn_AIL_waveOutClose);
		WriteLog("_AIL_digital_handle_release           %x\n", lpfn_AIL_digital_handle_release);
		WriteLog("_AIL_digital_handle_reacquire         %x\n", lpfn_AIL_digital_handle_reacquire);
		WriteLog("_AIL_open_input                       %x\n", lpfn_AIL_open_input);
		WriteLog("_AIL_close_input                      %x\n", lpfn_AIL_close_input);
		WriteLog("_AIL_get_input_info                   %x\n", lpfn_AIL_get_input_info);
		WriteLog("_AIL_set_input_state                  %x\n", lpfn_AIL_set_input_state);
		WriteLog("_AIL_digital_CPU_percent              %x\n", lpfn_AIL_digital_CPU_percent);
		WriteLog("_AIL_digital_latency                  %x\n", lpfn_AIL_digital_latency);
		WriteLog("_AIL_allocate_sample_handle           %x\n", lpfn_AIL_allocate_sample_handle);
		WriteLog("_AIL_allocate_file_sample             %x\n", lpfn_AIL_allocate_file_sample);
		WriteLog("_AIL_release_sample_handle            %x\n", lpfn_AIL_release_sample_handle);
		WriteLog("_AIL_init_sample                      %x\n", lpfn_AIL_init_sample);
		WriteLog("_AIL_set_sample_file                  %x\n", lpfn_AIL_set_sample_file);
		WriteLog("_AIL_set_named_sample_file            %x\n", lpfn_AIL_set_named_sample_file);
		WriteLog("_AIL_set_sample_processor             %x\n", lpfn_AIL_set_sample_processor);
		WriteLog("_AIL_set_stream_processor             %x\n", lpfn_AIL_set_stream_processor);
		WriteLog("_AIL_set_DLS_processor                %x\n", lpfn_AIL_set_DLS_processor);
		WriteLog("_AIL_set_digital_driver_processor     %x\n", lpfn_AIL_set_digital_driver_processor);
		WriteLog("_AIL_set_sample_address               %x\n", lpfn_AIL_set_sample_address);
		WriteLog("_AIL_set_sample_type                  %x\n", lpfn_AIL_set_sample_type);
		WriteLog("_AIL_set_sample_adpcm_block_size      %x\n", lpfn_AIL_set_sample_adpcm_block_size);
		WriteLog("_AIL_start_sample                     %x\n", lpfn_AIL_start_sample);
		WriteLog("_AIL_stop_sample                      %x\n", lpfn_AIL_stop_sample);
		WriteLog("_AIL_resume_sample                    %x\n", lpfn_AIL_resume_sample);
		WriteLog("_AIL_end_sample                       %x\n", lpfn_AIL_end_sample);
		WriteLog("_AIL_set_sample_playback_rate         %x\n", lpfn_AIL_set_sample_playback_rate);
		WriteLog("_AIL_set_sample_volume_pan            %x\n", lpfn_AIL_set_sample_volume_pan);
		WriteLog("_AIL_set_sample_volume_levels         %x\n", lpfn_AIL_set_sample_volume_levels);
		WriteLog("_AIL_set_sample_reverb_levels         %x\n", lpfn_AIL_set_sample_reverb_levels);
		WriteLog("_AIL_set_sample_low_pass_cut_off      %x\n", lpfn_AIL_set_sample_low_pass_cut_off);
		WriteLog("_AIL_set_sample_loop_count            %x\n", lpfn_AIL_set_sample_loop_count);
		WriteLog("_AIL_set_sample_loop_block            %x\n", lpfn_AIL_set_sample_loop_block);
		WriteLog("_AIL_sample_status                    %x\n", lpfn_AIL_sample_status);
		WriteLog("_AIL_sample_playback_rate             %x\n", lpfn_AIL_sample_playback_rate);
		WriteLog("_AIL_sample_volume_pan                %x\n", lpfn_AIL_sample_volume_pan);
		WriteLog("_AIL_sample_volume_levels             %x\n", lpfn_AIL_sample_volume_levels);
		WriteLog("_AIL_sample_reverb_levels             %x\n", lpfn_AIL_sample_reverb_levels);
		WriteLog("_AIL_sample_low_pass_cut_off          %x\n", lpfn_AIL_sample_low_pass_cut_off);
		WriteLog("_AIL_sample_loop_count                %x\n", lpfn_AIL_sample_loop_count);
		WriteLog("_AIL_set_digital_master_volume_level  %x\n", lpfn_AIL_set_digital_master_volume_level);
		WriteLog("_AIL_digital_master_volume_level      %x\n", lpfn_AIL_digital_master_volume_level);
		WriteLog("_AIL_set_digital_master_reverb_levels %x\n", lpfn_AIL_set_digital_master_reverb_levels);
		WriteLog("_AIL_set_digital_master_room_type     %x\n", lpfn_AIL_set_digital_master_room_type);
		WriteLog("_AIL_digital_master_reverb_levels     %x\n", lpfn_AIL_digital_master_reverb_levels);
		WriteLog("_AIL_set_digital_master_reverb        %x\n", lpfn_AIL_set_digital_master_reverb);
		WriteLog("_AIL_digital_master_reverb            %x\n", lpfn_AIL_digital_master_reverb);
		WriteLog("_AIL_minimum_sample_buffer_size       %x\n", lpfn_AIL_minimum_sample_buffer_size);
		WriteLog("_AIL_sample_buffer_ready              %x\n", lpfn_AIL_sample_buffer_ready);
		WriteLog("_AIL_load_sample_buffer               %x\n", lpfn_AIL_load_sample_buffer);
		WriteLog("_AIL_sample_buffer_info               %x\n", lpfn_AIL_sample_buffer_info);
		WriteLog("_AIL_sample_granularity               %x\n", lpfn_AIL_sample_granularity);
		WriteLog("_AIL_set_sample_position              %x\n", lpfn_AIL_set_sample_position);
		WriteLog("_AIL_sample_position                  %x\n", lpfn_AIL_sample_position);
		WriteLog("_AIL_register_SOB_callback            %x\n", lpfn_AIL_register_SOB_callback);
		WriteLog("_AIL_register_EOB_callback            %x\n", lpfn_AIL_register_EOB_callback);
		WriteLog("_AIL_register_EOS_callback            %x\n", lpfn_AIL_register_EOS_callback);
		WriteLog("_AIL_register_EOF_callback            %x\n", lpfn_AIL_register_EOF_callback);
		WriteLog("_AIL_set_sample_user_data             %x\n", lpfn_AIL_set_sample_user_data);
		WriteLog("_AIL_sample_user_data                 %x\n", lpfn_AIL_sample_user_data);
		WriteLog("_AIL_active_sample_count              %x\n", lpfn_AIL_active_sample_count);
		WriteLog("_AIL_digital_configuration            %x\n", lpfn_AIL_digital_configuration);
		WriteLog("_AIL_get_DirectSound_info             %x\n", lpfn_AIL_get_DirectSound_info);
		WriteLog("_AIL_set_DirectSound_HWND             %x\n", lpfn_AIL_set_DirectSound_HWND);
		WriteLog("_AIL_open_XMIDI_driver                %x\n", lpfn_AIL_open_XMIDI_driver);
		WriteLog("_AIL_close_XMIDI_driver               %x\n", lpfn_AIL_close_XMIDI_driver);
		WriteLog("_AIL_midiOutOpen                      %x\n", lpfn_AIL_midiOutOpen);
		WriteLog("_AIL_midiOutClose                     %x\n", lpfn_AIL_midiOutClose);
		WriteLog("_AIL_MIDI_handle_release              %x\n", lpfn_AIL_MIDI_handle_release);
		WriteLog("_AIL_MIDI_handle_reacquire            %x\n", lpfn_AIL_MIDI_handle_reacquire);
		WriteLog("_AIL_allocate_sequence_handle         %x\n", lpfn_AIL_allocate_sequence_handle);
		WriteLog("_AIL_release_sequence_handle          %x\n", lpfn_AIL_release_sequence_handle);
		WriteLog("_AIL_init_sequence                    %x\n", lpfn_AIL_init_sequence);
		WriteLog("_AIL_start_sequence                   %x\n", lpfn_AIL_start_sequence);
		WriteLog("_AIL_stop_sequence                    %x\n", lpfn_AIL_stop_sequence);
		WriteLog("_AIL_resume_sequence                  %x\n", lpfn_AIL_resume_sequence);
		WriteLog("_AIL_end_sequence                     %x\n", lpfn_AIL_end_sequence);
		WriteLog("_AIL_set_sequence_tempo               %x\n", lpfn_AIL_set_sequence_tempo);
		WriteLog("_AIL_set_sequence_volume              %x\n", lpfn_AIL_set_sequence_volume);
		WriteLog("_AIL_set_sequence_loop_count          %x\n", lpfn_AIL_set_sequence_loop_count);
		WriteLog("_AIL_sequence_status                  %x\n", lpfn_AIL_sequence_status);
		WriteLog("_AIL_sequence_tempo                   %x\n", lpfn_AIL_sequence_tempo);
		WriteLog("_AIL_sequence_volume                  %x\n", lpfn_AIL_sequence_volume);
		WriteLog("_AIL_sequence_loop_count              %x\n", lpfn_AIL_sequence_loop_count);
		WriteLog("_AIL_set_XMIDI_master_volume          %x\n", lpfn_AIL_set_XMIDI_master_volume);
		WriteLog("_AIL_XMIDI_master_volume              %x\n", lpfn_AIL_XMIDI_master_volume);
		WriteLog("_AIL_active_sequence_count            %x\n", lpfn_AIL_active_sequence_count);
		WriteLog("_AIL_controller_value                 %x\n", lpfn_AIL_controller_value);
		WriteLog("_AIL_channel_notes                    %x\n", lpfn_AIL_channel_notes);
		WriteLog("_AIL_sequence_position                %x\n", lpfn_AIL_sequence_position);
		WriteLog("_AIL_branch_index                     %x\n", lpfn_AIL_branch_index);
		WriteLog("_AIL_register_prefix_callback         %x\n", lpfn_AIL_register_prefix_callback);
		WriteLog("_AIL_register_trigger_callback        %x\n", lpfn_AIL_register_trigger_callback);
		WriteLog("_AIL_register_sequence_callback       %x\n", lpfn_AIL_register_sequence_callback);
		WriteLog("_AIL_register_beat_callback           %x\n", lpfn_AIL_register_beat_callback);
		WriteLog("_AIL_register_event_callback          %x\n", lpfn_AIL_register_event_callback);
		WriteLog("_AIL_register_timbre_callback         %x\n", lpfn_AIL_register_timbre_callback);
		WriteLog("_AIL_set_sequence_user_data           %x\n", lpfn_AIL_set_sequence_user_data);
		WriteLog("_AIL_sequence_user_data               %x\n", lpfn_AIL_sequence_user_data);
		WriteLog("_AIL_register_ICA_array               %x\n", lpfn_AIL_register_ICA_array);
		WriteLog("_AIL_lock_channel                     %x\n", lpfn_AIL_lock_channel);
		WriteLog("_AIL_release_channel                  %x\n", lpfn_AIL_release_channel);
		WriteLog("_AIL_map_sequence_channel             %x\n", lpfn_AIL_map_sequence_channel);
		WriteLog("_AIL_true_sequence_channel            %x\n", lpfn_AIL_true_sequence_channel);
		WriteLog("_AIL_send_channel_voice_message       %x\n", lpfn_AIL_send_channel_voice_message);
		WriteLog("_AIL_send_sysex_message               %x\n", lpfn_AIL_send_sysex_message);
		WriteLog("_AIL_create_wave_synthesizer          %x\n", lpfn_AIL_create_wave_synthesizer);
		WriteLog("_AIL_destroy_wave_synthesizer         %x\n", lpfn_AIL_destroy_wave_synthesizer);
		WriteLog("_AIL_file_error                       %x\n", lpfn_AIL_file_error);
		WriteLog("_AIL_file_size                        %x\n", lpfn_AIL_file_size);
		WriteLog("_AIL_file_read                        %x\n", lpfn_AIL_file_read);
		WriteLog("_AIL_file_write                       %x\n", lpfn_AIL_file_write);
		WriteLog("_AIL_WAV_file_write                   %x\n", lpfn_AIL_WAV_file_write);
		WriteLog("_AIL_serve                            %x\n", lpfn_AIL_serve);
		WriteLog("_AIL_redbook_open                     %x\n", lpfn_AIL_redbook_open);
		WriteLog("_AIL_redbook_open_drive               %x\n", lpfn_AIL_redbook_open_drive);
		WriteLog("_AIL_redbook_close                    %x\n", lpfn_AIL_redbook_close);
		WriteLog("_AIL_redbook_eject                    %x\n", lpfn_AIL_redbook_eject);
		WriteLog("_AIL_redbook_retract                  %x\n", lpfn_AIL_redbook_retract);
		WriteLog("_AIL_redbook_status                   %x\n", lpfn_AIL_redbook_status);
		WriteLog("_AIL_redbook_tracks                   %x\n", lpfn_AIL_redbook_tracks);
		WriteLog("_AIL_redbook_track                    %x\n", lpfn_AIL_redbook_track);
		WriteLog("_AIL_redbook_track_info               %x\n", lpfn_AIL_redbook_track_info);
		WriteLog("_AIL_redbook_id                       %x\n", lpfn_AIL_redbook_id);
		WriteLog("_AIL_redbook_position                 %x\n", lpfn_AIL_redbook_position);
		WriteLog("_AIL_redbook_play                     %x\n", lpfn_AIL_redbook_play);
		WriteLog("_AIL_redbook_stop                     %x\n", lpfn_AIL_redbook_stop);
		WriteLog("_AIL_redbook_pause                    %x\n", lpfn_AIL_redbook_pause);
		WriteLog("_AIL_redbook_resume                   %x\n", lpfn_AIL_redbook_resume);
		WriteLog("_AIL_redbook_volume_level             %x\n", lpfn_AIL_redbook_volume_level);
		WriteLog("_AIL_redbook_set_volume_level         %x\n", lpfn_AIL_redbook_set_volume_level);
		WriteLog("_AIL_quick_startup                    %x\n", lpfn_AIL_quick_startup);
		WriteLog("_AIL_quick_shutdown                   %x\n", lpfn_AIL_quick_shutdown);
		WriteLog("_AIL_quick_handles                    %x\n", lpfn_AIL_quick_handles);
		WriteLog("_AIL_quick_load                       %x\n", lpfn_AIL_quick_load);
		WriteLog("_AIL_quick_load_mem                   %x\n", lpfn_AIL_quick_load_mem);
		WriteLog("_AIL_quick_copy                       %x\n", lpfn_AIL_quick_copy);
		WriteLog("_AIL_quick_unload                     %x\n", lpfn_AIL_quick_unload);
		WriteLog("_AIL_quick_play                       %x\n", lpfn_AIL_quick_play);
		WriteLog("_AIL_quick_halt                       %x\n", lpfn_AIL_quick_halt);
		WriteLog("_AIL_quick_status                     %x\n", lpfn_AIL_quick_status);
		WriteLog("_AIL_quick_load_and_play              %x\n", lpfn_AIL_quick_load_and_play);
		WriteLog("_AIL_quick_set_speed                  %x\n", lpfn_AIL_quick_set_speed);
		WriteLog("_AIL_quick_set_volume                 %x\n", lpfn_AIL_quick_set_volume);
		WriteLog("_AIL_quick_set_reverb_levels          %x\n", lpfn_AIL_quick_set_reverb_levels);
		WriteLog("_AIL_quick_set_low_pass_cut_off       %x\n", lpfn_AIL_quick_set_low_pass_cut_off);
		WriteLog("_AIL_open_stream                      %x\n", lpfn_AIL_open_stream);
		WriteLog("_AIL_close_stream                     %x\n", lpfn_AIL_close_stream);
		WriteLog("_AIL_service_stream                   %x\n", lpfn_AIL_service_stream);
		WriteLog("_AIL_start_stream                     %x\n", lpfn_AIL_start_stream);
		WriteLog("_AIL_pause_stream                     %x\n", lpfn_AIL_pause_stream);
		WriteLog("_AIL_set_stream_volume_pan            %x\n", lpfn_AIL_set_stream_volume_pan);
		WriteLog("_AIL_set_stream_volume_levels         %x\n", lpfn_AIL_set_stream_volume_levels);
		WriteLog("_AIL_set_stream_reverb_levels         %x\n", lpfn_AIL_set_stream_reverb_levels);
		WriteLog("_AIL_set_stream_low_pass_cut_off      %x\n", lpfn_AIL_set_stream_low_pass_cut_off);
		WriteLog("_AIL_stream_volume_pan                %x\n", lpfn_AIL_stream_volume_pan);
		WriteLog("_AIL_stream_volume_levels             %x\n", lpfn_AIL_stream_volume_levels);
		WriteLog("_AIL_stream_reverb_levels             %x\n", lpfn_AIL_stream_reverb_levels);
		WriteLog("_AIL_stream_low_pass_cut_off          %x\n", lpfn_AIL_stream_low_pass_cut_off);
		WriteLog("_AIL_set_stream_playback_rate         %x\n", lpfn_AIL_set_stream_playback_rate);
		WriteLog("_AIL_stream_playback_rate             %x\n", lpfn_AIL_stream_playback_rate);
		WriteLog("_AIL_stream_loop_count                %x\n", lpfn_AIL_stream_loop_count);
		WriteLog("_AIL_set_stream_loop_block            %x\n", lpfn_AIL_set_stream_loop_block);
		WriteLog("_AIL_set_stream_loop_count            %x\n", lpfn_AIL_set_stream_loop_count);
		WriteLog("_AIL_stream_status                    %x\n", lpfn_AIL_stream_status);
		WriteLog("_AIL_set_stream_position              %x\n", lpfn_AIL_set_stream_position);
		WriteLog("_AIL_stream_position                  %x\n", lpfn_AIL_stream_position);
		WriteLog("_AIL_stream_info                      %x\n", lpfn_AIL_stream_info);
		WriteLog("_AIL_register_stream_callback         %x\n", lpfn_AIL_register_stream_callback);
		WriteLog("_AIL_auto_service_stream              %x\n", lpfn_AIL_auto_service_stream);
		WriteLog("_AIL_set_stream_user_data             %x\n", lpfn_AIL_set_stream_user_data);
		WriteLog("_AIL_stream_user_data                 %x\n", lpfn_AIL_stream_user_data);
		WriteLog("_AIL_DLS_open                         %x\n", lpfn_AIL_DLS_open);
		WriteLog("_AIL_DLS_close                        %x\n", lpfn_AIL_DLS_close);
		WriteLog("_AIL_DLS_load_file                    %x\n", lpfn_AIL_DLS_load_file);
		WriteLog("_AIL_DLS_load_memory                  %x\n", lpfn_AIL_DLS_load_memory);
		WriteLog("_AIL_DLS_unload                       %x\n", lpfn_AIL_DLS_unload);
		WriteLog("_AIL_DLS_compact                      %x\n", lpfn_AIL_DLS_compact);
		WriteLog("_AIL_DLS_set_reverb_levels            %x\n", lpfn_AIL_DLS_set_reverb_levels);
		WriteLog("_AIL_DLS_get_reverb_levels            %x\n", lpfn_AIL_DLS_get_reverb_levels);
		WriteLog("_AIL_DLS_get_info                     %x\n", lpfn_AIL_DLS_get_info);
		WriteLog("_AIL_set_sequence_ms_position         %x\n", lpfn_AIL_set_sequence_ms_position);
		WriteLog("_AIL_sequence_ms_position             %x\n", lpfn_AIL_sequence_ms_position);
		WriteLog("_AIL_sample_ms_position               %x\n", lpfn_AIL_sample_ms_position);
		WriteLog("_AIL_set_sample_ms_position           %x\n", lpfn_AIL_set_sample_ms_position);
		WriteLog("_AIL_stream_ms_position               %x\n", lpfn_AIL_stream_ms_position);
		WriteLog("_AIL_set_stream_ms_position           %x\n", lpfn_AIL_set_stream_ms_position);
		WriteLog("_AIL_quick_set_ms_position            %x\n", lpfn_AIL_quick_set_ms_position);
		WriteLog("_AIL_quick_ms_position                %x\n", lpfn_AIL_quick_ms_position);
		WriteLog("_AIL_quick_ms_length                  %x\n", lpfn_AIL_quick_ms_length);
		WriteLog("_AIL_quick_type                       %x\n", lpfn_AIL_quick_type);
		WriteLog("_AIL_MIDI_to_XMI                      %x\n", lpfn_AIL_MIDI_to_XMI);
		WriteLog("_AIL_compress_ADPCM                   %x\n", lpfn_AIL_compress_ADPCM);
		WriteLog("_AIL_decompress_ADPCM                 %x\n", lpfn_AIL_decompress_ADPCM);
		WriteLog("_AIL_WAV_info                         %x\n", lpfn_AIL_WAV_info);
		WriteLog("_AIL_file_type                        %x\n", lpfn_AIL_file_type);
		WriteLog("_AIL_find_DLS                         %x\n", lpfn_AIL_find_DLS);
		WriteLog("_AIL_extract_DLS                      %x\n", lpfn_AIL_extract_DLS);
		WriteLog("_AIL_primary_digital_driver           %x\n", lpfn_AIL_primary_digital_driver);
		WriteLog("_AIL_enumerate_filters                %x\n", lpfn_AIL_enumerate_filters);
		WriteLog("_AIL_open_filter                      %x\n", lpfn_AIL_open_filter);
		WriteLog("_AIL_close_filter                     %x\n", lpfn_AIL_close_filter);
		WriteLog("_AIL_enumerate_filter_attributes      %x\n", lpfn_AIL_enumerate_filter_attributes);
		WriteLog("_AIL_enumerate_filter_sample_attribute%x\n", lpfn_AIL_enumerate_filter_sample_attribute);
		WriteLog("_AIL_filter_attribute                 %x\n", lpfn_AIL_filter_attribute);
		WriteLog("_AIL_filter_sample_attribute          %x\n", lpfn_AIL_filter_sample_attribute);
		WriteLog("_AIL_filter_stream_attribute          %x\n", lpfn_AIL_filter_stream_attribute);
		WriteLog("_AIL_filter_DLS_attribute             %x\n", lpfn_AIL_filter_DLS_attribute);
		WriteLog("_AIL_set_filter_preference            %x\n", lpfn_AIL_set_filter_preference);
		WriteLog("_AIL_set_filter_sample_preference     %x\n", lpfn_AIL_set_filter_sample_preference);
		WriteLog("_AIL_set_filter_stream_preference     %x\n", lpfn_AIL_set_filter_stream_preference);
		WriteLog("_AIL_set_filter_DLS_preference        %x\n", lpfn_AIL_set_filter_DLS_preference);
		WriteLog("_AIL_enumerate_3D_providers           %x\n", lpfn_AIL_enumerate_3D_providers);
		WriteLog("_AIL_open_3D_provider                 %x\n", lpfn_AIL_open_3D_provider);
		WriteLog("_AIL_close_3D_provider                %x\n", lpfn_AIL_close_3D_provider);
		WriteLog("_AIL_enumerate_3D_provider_attributes %x\n", lpfn_AIL_enumerate_3D_provider_attributes);
		WriteLog("_AIL_enumerate_3D_sample_attributes   %x\n", lpfn_AIL_enumerate_3D_sample_attributes);
		WriteLog("_AIL_3D_provider_attribute            %x\n", lpfn_AIL_3D_provider_attribute);
		WriteLog("_AIL_3D_sample_attribute              %x\n", lpfn_AIL_3D_sample_attribute);
		WriteLog("_AIL_set_3D_provider_preference       %x\n", lpfn_AIL_set_3D_provider_preference);
		WriteLog("_AIL_set_3D_sample_preference         %x\n", lpfn_AIL_set_3D_sample_preference);
		WriteLog("_AIL_allocate_3D_sample_handle        %x\n", lpfn_AIL_allocate_3D_sample_handle);
		WriteLog("_AIL_release_3D_sample_handle         %x\n", lpfn_AIL_release_3D_sample_handle);
		WriteLog("_AIL_start_3D_sample                  %x\n", lpfn_AIL_start_3D_sample);
		WriteLog("_AIL_stop_3D_sample                   %x\n", lpfn_AIL_stop_3D_sample);
		WriteLog("_AIL_resume_3D_sample                 %x\n", lpfn_AIL_resume_3D_sample);
		WriteLog("_AIL_end_3D_sample                    %x\n", lpfn_AIL_end_3D_sample);
		WriteLog("_AIL_set_3D_sample_info               %x\n", lpfn_AIL_set_3D_sample_info);
		WriteLog("_AIL_set_3D_sample_file               %x\n", lpfn_AIL_set_3D_sample_file);
		WriteLog("_AIL_set_3D_sample_volume             %x\n", lpfn_AIL_set_3D_sample_volume);
		WriteLog("_AIL_set_3D_sample_playback_rate      %x\n", lpfn_AIL_set_3D_sample_playback_rate);
		WriteLog("_AIL_set_3D_sample_offset             %x\n", lpfn_AIL_set_3D_sample_offset);
		WriteLog("_AIL_set_3D_sample_loop_count         %x\n", lpfn_AIL_set_3D_sample_loop_count);
		WriteLog("_AIL_set_3D_sample_loop_block         %x\n", lpfn_AIL_set_3D_sample_loop_block);
		WriteLog("_AIL_set_3D_sample_obstruction        %x\n", lpfn_AIL_set_3D_sample_obstruction);
		WriteLog("_AIL_set_3D_sample_exclusion          %x\n", lpfn_AIL_set_3D_sample_exclusion);
		WriteLog("_AIL_set_3D_sample_occlusion          %x\n", lpfn_AIL_set_3D_sample_occlusion);
		WriteLog("_AIL_set_3D_sample_cone               %x\n", lpfn_AIL_set_3D_sample_cone);
		WriteLog("_AIL_set_3D_sample_effects_level      %x\n", lpfn_AIL_set_3D_sample_effects_level);
		WriteLog("_AIL_register_3D_EOS_callback         %x\n", lpfn_AIL_register_3D_EOS_callback);
		WriteLog("_AIL_3D_sample_obstruction            %x\n", lpfn_AIL_3D_sample_obstruction);
		WriteLog("_AIL_3D_sample_exclusion              %x\n", lpfn_AIL_3D_sample_exclusion);
		WriteLog("_AIL_3D_sample_occlusion              %x\n", lpfn_AIL_3D_sample_occlusion);
		WriteLog("_AIL_3D_sample_cone                   %x\n", lpfn_AIL_3D_sample_cone);
		WriteLog("_AIL_3D_sample_effects_level          %x\n", lpfn_AIL_3D_sample_effects_level);
		WriteLog("_AIL_3D_sample_status                 %x\n", lpfn_AIL_3D_sample_status);
		WriteLog("_AIL_3D_sample_volume                 %x\n", lpfn_AIL_3D_sample_volume);
		WriteLog("_AIL_3D_sample_playback_rate          %x\n", lpfn_AIL_3D_sample_playback_rate);
		WriteLog("_AIL_3D_sample_offset                 %x\n", lpfn_AIL_3D_sample_offset);
		WriteLog("_AIL_3D_sample_length                 %x\n", lpfn_AIL_3D_sample_length);
		WriteLog("_AIL_3D_sample_loop_count             %x\n", lpfn_AIL_3D_sample_loop_count);
		WriteLog("_AIL_set_3D_sample_distances          %x\n", lpfn_AIL_set_3D_sample_distances);
		WriteLog("_AIL_3D_sample_distances              %x\n", lpfn_AIL_3D_sample_distances);
		WriteLog("_AIL_set_3D_user_data                 %x\n", lpfn_AIL_set_3D_user_data);
		WriteLog("_AIL_3D_user_data                     %x\n", lpfn_AIL_3D_user_data);
		WriteLog("_AIL_active_3D_sample_count           %x\n", lpfn_AIL_active_3D_sample_count);
		WriteLog("_AIL_3D_room_type                     %x\n", lpfn_AIL_3D_room_type);
		WriteLog("_AIL_set_3D_room_type                 %x\n", lpfn_AIL_set_3D_room_type);
		WriteLog("_AIL_3D_speaker_type                  %x\n", lpfn_AIL_3D_speaker_type);
		WriteLog("_AIL_set_3D_speaker_type              %x\n", lpfn_AIL_set_3D_speaker_type);
		WriteLog("_AIL_3D_rolloff_factor                %x\n", lpfn_AIL_3D_rolloff_factor);
		WriteLog("_AIL_set_3D_rolloff_factor            %x\n", lpfn_AIL_set_3D_rolloff_factor);
		WriteLog("_AIL_3D_doppler_factor                %x\n", lpfn_AIL_3D_doppler_factor);
		WriteLog("_AIL_set_3D_doppler_factor            %x\n", lpfn_AIL_set_3D_doppler_factor);
		WriteLog("_AIL_3D_distance_factor               %x\n", lpfn_AIL_3D_distance_factor);
		WriteLog("_AIL_set_3D_distance_factor           %x\n", lpfn_AIL_set_3D_distance_factor);
		WriteLog("_AIL_open_3D_listener                 %x\n", lpfn_AIL_open_3D_listener);
		WriteLog("_AIL_close_3D_listener                %x\n", lpfn_AIL_close_3D_listener);
		WriteLog("_AIL_open_3D_object                   %x\n", lpfn_AIL_open_3D_object);
		WriteLog("_AIL_close_3D_object                  %x\n", lpfn_AIL_close_3D_object);
		WriteLog("_AIL_set_3D_position                  %x\n", lpfn_AIL_set_3D_position);
		WriteLog("_AIL_set_3D_velocity                  %x\n", lpfn_AIL_set_3D_velocity);
		WriteLog("_AIL_set_3D_velocity_vector           %x\n", lpfn_AIL_set_3D_velocity_vector);
		WriteLog("_AIL_set_3D_orientation               %x\n", lpfn_AIL_set_3D_orientation);
		WriteLog("_AIL_3D_position                      %x\n", lpfn_AIL_3D_position);
		WriteLog("_AIL_3D_velocity                      %x\n", lpfn_AIL_3D_velocity);
		WriteLog("_AIL_3D_orientation                   %x\n", lpfn_AIL_3D_orientation);
		WriteLog("_AIL_update_3D_position               %x\n", lpfn_AIL_update_3D_position);
		WriteLog("_AIL_auto_update_3D_position          %x\n", lpfn_AIL_auto_update_3D_position);
		WriteLog("_AIL_size_processed_digital_audio     %x\n", lpfn_AIL_size_processed_digital_audio);
		WriteLog("_AIL_process_digital_audio            %x\n", lpfn_AIL_process_digital_audio);
		WriteLog("_AIL_merge_DLS_with_XMI               %x\n", lpfn_AIL_merge_DLS_with_XMI);
		WriteLog("_AIL_compress_DLS                     %x\n", lpfn_AIL_compress_DLS);
		WriteLog("_AIL_filter_DLS_with_XMI              %x\n", lpfn_AIL_filter_DLS_with_XMI);
		WriteLog("_AIL_compress_ASI                     %x\n", lpfn_AIL_compress_ASI);
		WriteLog("_AIL_decompress_ASI                   %x\n", lpfn_AIL_decompress_ASI);
		WriteLog("_AIL_request_EOB_ASI_reset            %x\n", lpfn_AIL_request_EOB_ASI_reset);
		WriteLog("_AIL_set_redist_directory             %x\n", lpfn_AIL_set_redist_directory);
		WriteLog("_MIX_RIB_MAIN                         %x\n", lpfn_MIX_RIB_MAIN);
		WriteLog("_AIL_mem_use_malloc                   %x\n", lpfn_AIL_mem_use_malloc);
		WriteLog("_AIL_mem_use_free                     %x\n", lpfn_AIL_mem_use_free);
		WriteLog("AIL_sprintf                           %x\n", lpfnAIL_sprintf);
		WriteLog("DLSMSSOpen                            %x\n", lpfnDLSMSSOpen);
		WriteLog("DLSClose                              %x\n", lpfnDLSClose);
		WriteLog("DLSLoadFile                           %x\n", lpfnDLSLoadFile);
		WriteLog("DLSLoadMemFile                        %x\n", lpfnDLSLoadMemFile);
		WriteLog("DLSGetInfo                            %x\n", lpfnDLSGetInfo);
		WriteLog("DLSCompactMemory                      %x\n", lpfnDLSCompactMemory);
		WriteLog("DLSUnloadAll                          %x\n", lpfnDLSUnloadAll);
		WriteLog("DLSUnloadFile                         %x\n", lpfnDLSUnloadFile);
		WriteLog("DLSSetAttribute                       %x\n", lpfnDLSSetAttribute);
		WriteLog("_DLSMSSGetCPU                         %x\n", lpfn_DLSMSSGetCPU);
		WriteLog("-- Mss32.dll Export Table Log End --\n");

		DebugLog("Mss32.DLX 파일에서 익스포트 주소를 얻는데 실패했습니다.\n");
		WriteLog("Mss32 Hook 설치가 실패했습니다.\n");
		return false;
	}

/*
	if (!lpfnIJLGetLibVersion ||
		!lpfnIJLInit ||
		!lpfnIJLFree ||
		!lpfnIJLRead ||
		!lpfnIJLWrite ||
		!lpfnIJLErrorStr )
	{
		DebugLog("Failed to get IJL.dat export addresses.\n");
		WriteLog("IJL hook installation failed.\n");
		return false;
	}
*/
	WriteLog("Mss32 Hook 설치를 마쳤습니다.\n");
	return true;
}

void CDBGHook::SetSSQuality(int quality)
{
	ssQuality = quality;
}

int CDBGHook::GetSSQuality(void)
{
	return ssQuality;
}
NAKED VOID __stdcall AIL_get_preference(BYTE)
{
	__asm JMP lpfn_AIL_get_preference
}
NAKED VOID __stdcall AIL_lock(VOID)
{
	__asm JMP lpfn_AIL_lock
}
NAKED VOID __stdcall AIL_unlock(VOID)
{
	__asm JMP lpfn_AIL_unlock
}
NAKED VOID __stdcall AIL_lock_mutex(VOID)
{
	__asm JMP lpfn_AIL_lock_mutex
}
NAKED VOID __stdcall AIL_unlock_mutex(VOID)
{
	__asm JMP lpfn_AIL_unlock_mutex
}
NAKED VOID __stdcall AIL_get_timer_highest_delay(VOID)
{
	__asm JMP lpfn_AIL_get_timer_highest_delay
}
/*
NAKED VOID __stdcall DllMain(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_DllMain
}
*/
NAKED VOID __stdcall RIB_load_static_provider_library(BYTE, BYTE)
{
	__asm JMP lpfn_RIB_load_static_provider_library
}
NAKED VOID RIB_alloc_provider_handle(VOID)
{
	__asm JMP lpfnRIB_alloc_provider_handle
}
NAKED VOID RIB_free_provider_handle(VOID)
{
	__asm JMP lpfnRIB_free_provider_handle
}
NAKED VOID RIB_load_provider_library(VOID)
{
	__asm JMP lpfnRIB_load_provider_library
}
NAKED VOID RIB_free_provider_library(VOID)
{
	__asm JMP lpfnRIB_free_provider_library
}
NAKED VOID RIB_register_interface(VOID)
{
	__asm JMP lpfnRIB_register_interface
}
NAKED VOID RIB_request_interface(VOID)
{
	__asm JMP lpfnRIB_request_interface
}
NAKED VOID RIB_request_interface_entry(VOID)
{
	__asm JMP lpfnRIB_request_interface_entry
}
NAKED VOID RIB_unregister_interface(VOID)
{
	__asm JMP lpfnRIB_unregister_interface
}
NAKED VOID RIB_enumerate_interface(VOID)
{
	__asm JMP lpfnRIB_enumerate_interface
}
NAKED VOID __stdcall RIB_enumerate_providers(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_RIB_enumerate_providers
}
NAKED VOID RIB_type_string(VOID)
{
	__asm JMP lpfnRIB_type_string
}
NAKED VOID RIB_find_file_provider(void)
{
	__asm JMP lpfnRIB_find_file_provider
}
NAKED VOID __stdcall RIB_find_files_provider(BYTE,BYTE,BYTE,BYTE,BYTE)
{
	__asm JMP lpfn_RIB_find_files_provider
}
NAKED VOID __stdcall RIB_find_file_dec_provider(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_RIB_find_file_dec_provider
}
NAKED VOID __stdcall RIB_find_provider(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_RIB_find_provider
}
NAKED VOID __stdcall RIB_load_application_providers(BYTE)
{
	__asm JMP lpfn_RIB_load_application_providers
}
NAKED VOID __stdcall RIB_set_provider_user_data(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_RIB_set_provider_user_data
}
NAKED VOID __stdcall RIB_provider_user_data(BYTE, BYTE)
{
	__asm JMP lpfn_RIB_provider_user_data
}
NAKED VOID __stdcall RIB_set_provider_system_data(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_RIB_set_provider_system_data
}
NAKED VOID __stdcall RIB_provider_system_data(BYTE, BYTE)
{
	__asm JMP lpfn_RIB_provider_system_data
}
NAKED VOID  RIB_error(void)
{
	__asm JMP lpfnRIB_error
}
NAKED VOID __stdcall AIL_set_file_async_callbacks(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_file_async_callbacks
}
NAKED VOID __stdcall AIL_set_file_callbacks(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_file_callbacks
}
NAKED VOID __stdcall AIL_list_DLS(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_list_DLS
}
NAKED VOID __stdcall AIL_list_MIDI(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_list_MIDI
}
NAKED VOID stream_background(void)
{
	__asm JMP lpfnstream_background
}
NAKED VOID __stdcall AIL_ms_count(VOID)
{
	__asm JMP lpfn_AIL_ms_count
}
NAKED VOID __stdcall AIL_us_count(VOID)
{
	__asm JMP lpfn_AIL_us_count
}
NAKED VOID __stdcall AIL_MMX_available(VOID)
{
	__asm JMP lpfn_AIL_MMX_available
}
NAKED VOID AIL_debug_printf(VOID)
{
	__asm JMP lpfnAIL_debug_printf
}
NAKED VOID __stdcall AIL_startup(VOID)
{
	__asm JMP lpfn_AIL_startup
}
NAKED VOID __stdcall AIL_shutdown(VOID)
{
	__asm JMP lpfn_AIL_shutdown
}
NAKED VOID __stdcall AIL_HWND(VOID)
{
	__asm JMP lpfn_AIL_HWND
}
NAKED VOID __stdcall AIL_mem_alloc_lock(BYTE)
{
	__asm JMP lpfn_AIL_mem_alloc_lock
}
NAKED VOID __stdcall AIL_mem_free_lock(BYTE)
{
	__asm JMP lpfn_AIL_mem_free_lock
}
NAKED VOID __stdcall AIL_set_preference(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_preference
}
NAKED VOID __stdcall AIL_last_error(VOID)
{
	__asm JMP lpfn_AIL_last_error
}
NAKED VOID __stdcall AIL_set_error(BYTE)
{
	__asm JMP lpfn_AIL_set_error
}
NAKED VOID __stdcall AIL_delay(BYTE)
{
	__asm JMP lpfn_AIL_delay
}
NAKED VOID __stdcall AIL_background(VOID)
{
	__asm JMP lpfn_AIL_background
}
NAKED VOID __stdcall AIL_register_timer(BYTE)
{
	__asm JMP lpfn_AIL_register_timer
}
NAKED VOID __stdcall AIL_set_timer_user(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_timer_user
}
NAKED VOID __stdcall AIL_set_timer_period(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_timer_period
}
NAKED VOID __stdcall AIL_set_timer_frequency(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_timer_frequency
}
NAKED VOID __stdcall AIL_set_timer_divisor(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_timer_divisor
}
NAKED VOID __stdcall AIL_start_timer(BYTE)
{
	__asm JMP lpfn_AIL_start_timer
}
NAKED VOID __stdcall AIL_start_all_timers(VOID)
{
	__asm JMP lpfn_AIL_start_all_timers
}
NAKED VOID __stdcall AIL_stop_timer(BYTE)
{
	__asm JMP lpfn_AIL_stop_timer
}
NAKED VOID __stdcall AIL_stop_all_timers(VOID)
{
	__asm JMP lpfn_AIL_stop_all_timers
}
NAKED VOID __stdcall AIL_release_timer_handle(BYTE)
{
	__asm JMP lpfn_AIL_release_timer_handle
}
NAKED VOID __stdcall AIL_release_all_timers(VOID)
{
	__asm JMP lpfn_AIL_release_all_timers
}
NAKED VOID __stdcall AIL_open_digital_driver(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_open_digital_driver
}
NAKED VOID __stdcall AIL_close_digital_driver(BYTE)
{
	__asm JMP lpfn_AIL_close_digital_driver
}
NAKED VOID __stdcall AIL_waveOutOpen(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_waveOutOpen
}
NAKED VOID __stdcall AIL_waveOutClose(BYTE)
{
	__asm JMP lpfn_AIL_waveOutClose
}
NAKED VOID __stdcall AIL_digital_handle_release(BYTE)
{
	__asm JMP lpfn_AIL_digital_handle_release
}
NAKED VOID __stdcall AIL_digital_handle_reacquire(BYTE)
{
	__asm JMP lpfn_AIL_digital_handle_reacquire
}
NAKED VOID __stdcall AIL_open_input(BYTE)
{
	__asm JMP lpfn_AIL_open_input
}
NAKED VOID __stdcall AIL_close_input(BYTE)
{
	__asm JMP lpfn_AIL_close_input
}
NAKED VOID __stdcall AIL_get_input_info(BYTE)
{
	__asm JMP lpfn_AIL_get_input_info
}
NAKED VOID __stdcall AIL_set_input_state(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_input_state
}
NAKED VOID __stdcall AIL_digital_CPU_percent(BYTE)
{
	__asm JMP lpfn_AIL_digital_CPU_percent
}
NAKED VOID __stdcall AIL_digital_latency(BYTE)
{
	__asm JMP lpfn_AIL_digital_latency
}
NAKED VOID __stdcall AIL_allocate_sample_handle(BYTE)
{
	__asm JMP lpfn_AIL_allocate_sample_handle
}
NAKED VOID __stdcall AIL_allocate_file_sample(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_allocate_file_sample
}
NAKED VOID __stdcall AIL_release_sample_handle(BYTE)
{
	__asm JMP lpfn_AIL_release_sample_handle
}
NAKED VOID __stdcall AIL_init_sample(BYTE)
{
	__asm JMP lpfn_AIL_init_sample
}
NAKED VOID __stdcall AIL_set_sample_file(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_file
}
NAKED VOID __stdcall AIL_set_named_sample_file(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_named_sample_file
}
NAKED VOID __stdcall AIL_set_sample_processor(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_processor
}
NAKED VOID __stdcall AIL_set_stream_processor(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_processor
}
NAKED VOID __stdcall AIL_set_DLS_processor(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_DLS_processor
}
NAKED VOID __stdcall AIL_set_digital_driver_processor(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_digital_driver_processor
}
NAKED VOID __stdcall AIL_set_sample_address(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_address
}
NAKED VOID __stdcall AIL_set_sample_type(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_type
}
NAKED VOID __stdcall AIL_set_sample_adpcm_block_size(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_adpcm_block_size
}
NAKED VOID __stdcall AIL_start_sample(BYTE)
{
	__asm JMP lpfn_AIL_start_sample
}
NAKED VOID __stdcall AIL_stop_sample(BYTE)
{
	__asm JMP lpfn_AIL_stop_sample
}
NAKED VOID __stdcall AIL_resume_sample(BYTE)
{
	__asm JMP lpfn_AIL_resume_sample
}
NAKED VOID __stdcall AIL_end_sample(BYTE)
{
	__asm JMP lpfn_AIL_end_sample
}
NAKED VOID __stdcall AIL_set_sample_playback_rate(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_playback_rate
}
NAKED VOID __stdcall AIL_set_sample_volume_pan(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_volume_pan
}
NAKED VOID __stdcall AIL_set_sample_volume_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_volume_levels
}
NAKED VOID __stdcall AIL_set_sample_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_reverb_levels
}
NAKED VOID __stdcall AIL_set_sample_low_pass_cut_off(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_low_pass_cut_off
}
NAKED VOID __stdcall AIL_set_sample_loop_count(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_loop_count
}
NAKED VOID __stdcall AIL_set_sample_loop_block(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_loop_block
}
NAKED VOID __stdcall AIL_sample_status(BYTE)
{
	__asm JMP lpfn_AIL_sample_status
}
NAKED VOID __stdcall AIL_sample_playback_rate(BYTE)
{
	__asm JMP lpfn_AIL_sample_playback_rate
}
NAKED VOID __stdcall AIL_sample_volume_pan(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sample_volume_pan
}
NAKED VOID __stdcall AIL_sample_volume_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sample_volume_levels
}
NAKED VOID __stdcall AIL_sample_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sample_reverb_levels
}
NAKED VOID __stdcall AIL_sample_low_pass_cut_off(BYTE)
{
	__asm JMP lpfn_AIL_sample_low_pass_cut_off
}
NAKED VOID __stdcall AIL_sample_loop_count(BYTE)
{
	__asm JMP lpfn_AIL_sample_loop_count
}
NAKED VOID __stdcall AIL_set_digital_master_volume_level(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_digital_master_volume_level
}
NAKED VOID __stdcall AIL_digital_master_volume_level(BYTE)
{
	__asm JMP lpfn_AIL_digital_master_volume_level
}
NAKED VOID __stdcall AIL_set_digital_master_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_digital_master_reverb_levels
}
NAKED VOID __stdcall AIL_set_digital_master_room_type(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_digital_master_room_type
}
NAKED VOID __stdcall AIL_digital_master_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_digital_master_reverb_levels
}
NAKED VOID __stdcall AIL_set_digital_master_reverb(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_digital_master_reverb
}
NAKED VOID __stdcall AIL_digital_master_reverb(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_digital_master_reverb
}
NAKED VOID __stdcall AIL_minimum_sample_buffer_size(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_minimum_sample_buffer_size
}
NAKED VOID __stdcall AIL_sample_buffer_ready(BYTE)
{
	__asm JMP lpfn_AIL_sample_buffer_ready
}
NAKED VOID __stdcall AIL_load_sample_buffer(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_load_sample_buffer
}
NAKED VOID __stdcall AIL_sample_buffer_info(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sample_buffer_info
}
NAKED VOID __stdcall AIL_sample_granularity(BYTE)
{
	__asm JMP lpfn_AIL_sample_granularity
}
NAKED VOID __stdcall AIL_set_sample_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_position
}
NAKED VOID __stdcall AIL_sample_position(BYTE)
{
	__asm JMP lpfn_AIL_sample_position
}
NAKED VOID __stdcall AIL_register_SOB_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_SOB_callback
}
NAKED VOID __stdcall AIL_register_EOB_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_EOB_callback
}
NAKED VOID __stdcall AIL_register_EOS_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_EOS_callback
}
NAKED VOID __stdcall AIL_register_EOF_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_EOF_callback
}
NAKED VOID __stdcall AIL_set_sample_user_data(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_user_data
}
NAKED VOID __stdcall AIL_sample_user_data(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sample_user_data
}
NAKED VOID __stdcall AIL_active_sample_count(BYTE)
{
	__asm JMP lpfn_AIL_active_sample_count
}
NAKED VOID __stdcall AIL_digital_configuration(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_digital_configuration
}
NAKED VOID __stdcall AIL_get_DirectSound_info(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_get_DirectSound_info
}
NAKED VOID __stdcall AIL_set_DirectSound_HWND(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_DirectSound_HWND
}
NAKED VOID __stdcall AIL_open_XMIDI_driver(BYTE)
{
	__asm JMP lpfn_AIL_open_XMIDI_driver
}
NAKED VOID __stdcall AIL_close_XMIDI_driver(BYTE)
{
	__asm JMP lpfn_AIL_close_XMIDI_driver
}
NAKED VOID __stdcall AIL_midiOutOpen(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_midiOutOpen
}
NAKED VOID __stdcall AIL_midiOutClose(BYTE)
{
	__asm JMP lpfn_AIL_midiOutClose
}
NAKED VOID __stdcall AIL_MIDI_handle_release(BYTE)
{
	__asm JMP lpfn_AIL_MIDI_handle_release
}
NAKED VOID __stdcall AIL_MIDI_handle_reacquire(BYTE)
{
	__asm JMP lpfn_AIL_MIDI_handle_reacquire
}
NAKED VOID __stdcall AIL_allocate_sequence_handle(BYTE)
{
	__asm JMP lpfn_AIL_allocate_sequence_handle
}
NAKED VOID __stdcall AIL_release_sequence_handle(BYTE)
{
	__asm JMP lpfn_AIL_release_sequence_handle
}
NAKED VOID __stdcall AIL_init_sequence(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_init_sequence
}
NAKED VOID __stdcall AIL_start_sequence(BYTE)
{
	__asm JMP lpfn_AIL_start_sequence
}
NAKED VOID __stdcall AIL_stop_sequence(BYTE)
{
	__asm JMP lpfn_AIL_stop_sequence
}
NAKED VOID __stdcall AIL_resume_sequence(BYTE)
{
	__asm JMP lpfn_AIL_resume_sequence
}
NAKED VOID __stdcall AIL_end_sequence(BYTE)
{
	__asm JMP lpfn_AIL_end_sequence
}
NAKED VOID __stdcall AIL_set_sequence_tempo(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sequence_tempo
}
NAKED VOID __stdcall AIL_set_sequence_volume(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sequence_volume
}
NAKED VOID __stdcall AIL_set_sequence_loop_count(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sequence_loop_count
}
NAKED VOID __stdcall AIL_sequence_status(BYTE)
{
	__asm JMP lpfn_AIL_sequence_status
}
NAKED VOID __stdcall AIL_sequence_tempo(BYTE)
{
	__asm JMP lpfn_AIL_sequence_tempo
}
NAKED VOID __stdcall AIL_sequence_volume(BYTE)
{
	__asm JMP lpfn_AIL_sequence_volume
}
NAKED VOID __stdcall AIL_sequence_loop_count(BYTE)
{
	__asm JMP lpfn_AIL_sequence_loop_count
}
NAKED VOID __stdcall AIL_set_XMIDI_master_volume(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_XMIDI_master_volume
}
NAKED VOID __stdcall AIL_XMIDI_master_volume(BYTE)
{
	__asm JMP lpfn_AIL_XMIDI_master_volume
}
NAKED VOID __stdcall AIL_active_sequence_count(BYTE)
{
	__asm JMP lpfn_AIL_active_sequence_count
}
NAKED VOID __stdcall AIL_controller_value(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_controller_value
}
NAKED VOID __stdcall AIL_channel_notes(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_channel_notes
}
NAKED VOID __stdcall AIL_sequence_position(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sequence_position
}
NAKED VOID __stdcall AIL_branch_index(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_branch_index
}
NAKED VOID __stdcall AIL_register_prefix_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_prefix_callback
}
NAKED VOID __stdcall AIL_register_trigger_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_trigger_callback
}
NAKED VOID __stdcall AIL_register_sequence_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_sequence_callback
}
NAKED VOID __stdcall AIL_register_beat_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_beat_callback
}
NAKED VOID __stdcall AIL_register_event_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_event_callback
}
NAKED VOID __stdcall AIL_register_timbre_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_timbre_callback
}
NAKED VOID __stdcall AIL_set_sequence_user_data(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sequence_user_data
}
NAKED VOID __stdcall AIL_sequence_user_data(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sequence_user_data
}
NAKED VOID __stdcall AIL_register_ICA_array(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_ICA_array
}
NAKED VOID __stdcall AIL_lock_channel(BYTE)
{
	__asm JMP lpfn_AIL_lock_channel
}
NAKED VOID __stdcall AIL_release_channel(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_release_channel
}
NAKED VOID __stdcall AIL_map_sequence_channel(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_map_sequence_channel
}
NAKED VOID __stdcall AIL_true_sequence_channel(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_true_sequence_channel
}
NAKED VOID __stdcall AIL_send_channel_voice_message(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_send_channel_voice_message
}
NAKED VOID __stdcall AIL_send_sysex_message(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_send_sysex_message
}
NAKED VOID __stdcall AIL_create_wave_synthesizer(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_create_wave_synthesizer
}
NAKED VOID __stdcall AIL_destroy_wave_synthesizer(BYTE)
{
	__asm JMP lpfn_AIL_destroy_wave_synthesizer
}
NAKED VOID __stdcall AIL_file_error(VOID)
{
	__asm JMP lpfn_AIL_file_error
}
NAKED VOID __stdcall AIL_file_size(BYTE)
{
	__asm JMP lpfn_AIL_file_size
}
NAKED VOID __stdcall AIL_file_read(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_file_read
}
NAKED VOID __stdcall AIL_file_write(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_file_write
}
NAKED VOID __stdcall AIL_WAV_file_write(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_WAV_file_write
}
NAKED VOID __stdcall AIL_serve(VOID)
{
	__asm JMP lpfn_AIL_serve
}
NAKED VOID __stdcall AIL_redbook_open(BYTE)
{
	__asm JMP lpfn_AIL_redbook_open
}
NAKED VOID __stdcall AIL_redbook_open_drive(BYTE)
{
	__asm JMP lpfn_AIL_redbook_open_drive
}
NAKED VOID __stdcall AIL_redbook_close(BYTE)
{
	__asm JMP lpfn_AIL_redbook_close
}
NAKED VOID __stdcall AIL_redbook_eject(BYTE)
{
	__asm JMP lpfn_AIL_redbook_eject
}
NAKED VOID __stdcall AIL_redbook_retract(BYTE)
{
	__asm JMP lpfn_AIL_redbook_retract
}
NAKED VOID __stdcall AIL_redbook_status(BYTE)
{
	__asm JMP lpfn_AIL_redbook_status
}
NAKED VOID __stdcall AIL_redbook_tracks(BYTE)
{
	__asm JMP lpfn_AIL_redbook_tracks
}
NAKED VOID __stdcall AIL_redbook_track(BYTE)
{
	__asm JMP lpfn_AIL_redbook_track
}
NAKED VOID __stdcall AIL_redbook_track_info(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_redbook_track_info
}
NAKED VOID __stdcall AIL_redbook_id(BYTE)
{
	__asm JMP lpfn_AIL_redbook_id
}
NAKED VOID __stdcall AIL_redbook_position(BYTE)
{
	__asm JMP lpfn_AIL_redbook_position
}
NAKED VOID __stdcall AIL_redbook_play(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_redbook_play
}
NAKED VOID __stdcall AIL_redbook_stop(BYTE)
{
	__asm JMP lpfn_AIL_redbook_stop
}
NAKED VOID __stdcall AIL_redbook_pause(BYTE)
{
	__asm JMP lpfn_AIL_redbook_pause
}
NAKED VOID __stdcall AIL_redbook_resume(BYTE)
{
	__asm JMP lpfn_AIL_redbook_resume
}
NAKED VOID __stdcall AIL_redbook_volume_level(BYTE)
{
	__asm JMP lpfn_AIL_redbook_volume_level
}
NAKED VOID __stdcall AIL_redbook_set_volume_level(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_redbook_set_volume_level
}
NAKED VOID __stdcall AIL_quick_startup(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_startup
}
NAKED VOID __stdcall AIL_quick_shutdown(VOID)
{
	__asm JMP lpfn_AIL_quick_shutdown
}
NAKED VOID __stdcall AIL_quick_handles(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_handles
}
NAKED VOID __stdcall AIL_quick_load(BYTE)
{
	__asm JMP lpfn_AIL_quick_load
}
NAKED VOID __stdcall AIL_quick_load_mem(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_load_mem
}
NAKED VOID __stdcall AIL_quick_copy(BYTE)
{
	__asm JMP lpfn_AIL_quick_copy
}
NAKED VOID __stdcall AIL_quick_unload(BYTE)
{
	__asm JMP lpfn_AIL_quick_unload
}
NAKED VOID __stdcall AIL_quick_play(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_play
}
NAKED VOID __stdcall AIL_quick_halt(BYTE)
{
	__asm JMP lpfn_AIL_quick_halt
}
NAKED VOID __stdcall AIL_quick_status(BYTE)
{
	__asm JMP lpfn_AIL_quick_status
}
NAKED VOID __stdcall AIL_quick_load_and_play(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_load_and_play
}
NAKED VOID __stdcall AIL_quick_set_speed(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_set_speed
}
NAKED VOID __stdcall AIL_quick_set_volume(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_set_volume
}
NAKED VOID __stdcall AIL_quick_set_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_set_reverb_levels
}
NAKED VOID __stdcall AIL_quick_set_low_pass_cut_off(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_set_low_pass_cut_off
}
NAKED VOID __stdcall AIL_open_stream(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_open_stream
}
NAKED VOID __stdcall AIL_close_stream(BYTE)
{
	__asm JMP lpfn_AIL_close_stream
}
NAKED VOID __stdcall AIL_service_stream(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_service_stream
}
NAKED VOID __stdcall AIL_start_stream(BYTE)
{
	__asm JMP lpfn_AIL_start_stream
}
NAKED VOID __stdcall AIL_pause_stream(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_pause_stream
}
NAKED VOID __stdcall AIL_set_stream_volume_pan(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_volume_pan
}
NAKED VOID __stdcall AIL_set_stream_volume_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_volume_levels
}
NAKED VOID __stdcall AIL_set_stream_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_reverb_levels
}
NAKED VOID __stdcall AIL_set_stream_low_pass_cut_off(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_low_pass_cut_off
}
NAKED VOID __stdcall AIL_stream_volume_pan(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_stream_volume_pan
}
NAKED VOID __stdcall AIL_stream_volume_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_stream_volume_levels
}
NAKED VOID __stdcall AIL_stream_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_stream_reverb_levels
}
NAKED VOID __stdcall AIL_stream_low_pass_cut_off(BYTE)
{
	__asm JMP lpfn_AIL_stream_low_pass_cut_off
}
NAKED VOID __stdcall AIL_set_stream_playback_rate(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_playback_rate
}
NAKED VOID __stdcall AIL_stream_playback_rate(BYTE)
{
	__asm JMP lpfn_AIL_stream_playback_rate
}
NAKED VOID __stdcall AIL_stream_loop_count(BYTE)
{
	__asm JMP lpfn_AIL_stream_loop_count
}
NAKED VOID __stdcall AIL_set_stream_loop_block(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_loop_block
}
NAKED VOID __stdcall AIL_set_stream_loop_count(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_loop_count
}
NAKED VOID __stdcall AIL_stream_status(BYTE)
{
	__asm JMP lpfn_AIL_stream_status
}
NAKED VOID __stdcall AIL_set_stream_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_position
}
NAKED VOID __stdcall AIL_stream_position(BYTE)
{
	__asm JMP lpfn_AIL_stream_position
}
NAKED VOID __stdcall AIL_stream_info(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_stream_info
}
NAKED VOID __stdcall AIL_register_stream_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_stream_callback
}
NAKED VOID __stdcall AIL_auto_service_stream(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_auto_service_stream
}
NAKED VOID __stdcall AIL_set_stream_user_data(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_user_data
}
NAKED VOID __stdcall AIL_stream_user_data(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_stream_user_data
}
NAKED VOID __stdcall AIL_DLS_open(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_open
}
NAKED VOID __stdcall AIL_DLS_close(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_close
}
NAKED VOID __stdcall AIL_DLS_load_file(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_load_file
}
NAKED VOID __stdcall AIL_DLS_load_memory(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_load_memory
}
NAKED VOID __stdcall AIL_DLS_unload(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_unload
}
NAKED VOID __stdcall AIL_DLS_compact(BYTE)
{
	__asm JMP lpfn_AIL_DLS_compact
}
NAKED VOID __stdcall AIL_DLS_set_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_set_reverb_levels
}
NAKED VOID __stdcall AIL_DLS_get_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_get_reverb_levels
}
NAKED VOID __stdcall AIL_DLS_get_info(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_get_info
}
NAKED VOID __stdcall AIL_set_sequence_ms_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sequence_ms_position
}
NAKED VOID __stdcall AIL_sequence_ms_position(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sequence_ms_position
}
NAKED VOID __stdcall AIL_sample_ms_position(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sample_ms_position
}
NAKED VOID __stdcall AIL_set_sample_ms_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_ms_position
}
NAKED VOID __stdcall AIL_stream_ms_position(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_stream_ms_position
}
NAKED VOID __stdcall AIL_set_stream_ms_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_ms_position
}
NAKED VOID __stdcall AIL_quick_set_ms_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_set_ms_position
}
NAKED VOID __stdcall AIL_quick_ms_position(BYTE)
{
	__asm JMP lpfn_AIL_quick_ms_position
}
NAKED VOID __stdcall AIL_quick_ms_length(BYTE)
{
	__asm JMP lpfn_AIL_quick_ms_length
}
NAKED VOID __stdcall AIL_quick_type(BYTE)
{
	__asm JMP lpfn_AIL_quick_type
}
NAKED VOID __stdcall AIL_MIDI_to_XMI(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_MIDI_to_XMI
}
NAKED VOID __stdcall AIL_compress_ADPCM(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_compress_ADPCM
}
NAKED VOID __stdcall AIL_decompress_ADPCM(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_decompress_ADPCM
}
NAKED VOID __stdcall AIL_WAV_info(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_WAV_info
}
NAKED VOID __stdcall AIL_file_type(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_file_type
}
NAKED VOID __stdcall AIL_find_DLS(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_find_DLS
}
NAKED VOID __stdcall AIL_extract_DLS(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_extract_DLS
}
NAKED VOID __stdcall AIL_primary_digital_driver(BYTE)
{
	__asm JMP lpfn_AIL_primary_digital_driver
}
NAKED VOID __stdcall AIL_enumerate_filters(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_enumerate_filters
}
NAKED VOID __stdcall AIL_open_filter(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_open_filter
}
NAKED VOID __stdcall AIL_close_filter(BYTE)
{
	__asm JMP lpfn_AIL_close_filter
}
NAKED VOID __stdcall AIL_enumerate_filter_attributes(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_enumerate_filter_attributes
}
NAKED VOID _AIL_enumerate_filter_sample_attribute(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_enumerate_filter_sample_attribute
}
NAKED VOID __stdcall AIL_filter_attribute(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_filter_attribute
}
NAKED VOID __stdcall AIL_filter_sample_attribute(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_filter_sample_attribute
}
NAKED VOID __stdcall AIL_filter_stream_attribute(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_filter_stream_attribute
}
NAKED VOID __stdcall AIL_filter_DLS_attribute(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_filter_DLS_attribute
}
NAKED VOID __stdcall AIL_set_filter_preference(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_filter_preference
}
NAKED VOID __stdcall AIL_set_filter_sample_preference(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_filter_sample_preference
}
NAKED VOID __stdcall AIL_set_filter_stream_preference(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_filter_stream_preference
}
NAKED VOID __stdcall AIL_set_filter_DLS_preference(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_filter_DLS_preference
}
NAKED VOID __stdcall AIL_enumerate_3D_providers(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_enumerate_3D_providers
}
NAKED VOID __stdcall AIL_open_3D_provider(BYTE)
{
	__asm JMP lpfn_AIL_open_3D_provider
}
NAKED VOID __stdcall AIL_close_3D_provider(BYTE)
{
	__asm JMP lpfn_AIL_close_3D_provider
}
NAKED VOID __stdcall AIL_enumerate_3D_provider_attributes(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_enumerate_3D_provider_attributes
}
NAKED VOID __stdcall AIL_enumerate_3D_sample_attributes(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_enumerate_3D_sample_attributes
}
NAKED VOID __stdcall AIL_3D_provider_attribute(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_provider_attribute
}
NAKED VOID __stdcall AIL_3D_sample_attribute(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_attribute
}
NAKED VOID __stdcall AIL_set_3D_provider_preference(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_provider_preference
}
NAKED VOID __stdcall AIL_set_3D_sample_preference(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_preference
}
NAKED VOID __stdcall AIL_allocate_3D_sample_handle(BYTE)
{
	__asm JMP lpfn_AIL_allocate_3D_sample_handle
}
NAKED VOID __stdcall AIL_release_3D_sample_handle(BYTE)
{
	__asm JMP lpfn_AIL_release_3D_sample_handle
}
NAKED VOID __stdcall AIL_start_3D_sample(BYTE)
{
	__asm JMP lpfn_AIL_start_3D_sample
}
NAKED VOID __stdcall AIL_stop_3D_sample(BYTE)
{
	__asm JMP lpfn_AIL_stop_3D_sample
}
NAKED VOID __stdcall AIL_resume_3D_sample(BYTE)
{
	__asm JMP lpfn_AIL_resume_3D_sample
}
NAKED VOID __stdcall AIL_end_3D_sample(BYTE)
{
	__asm JMP lpfn_AIL_end_3D_sample
}
NAKED VOID __stdcall AIL_set_3D_sample_info(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_info
}
NAKED VOID __stdcall AIL_set_3D_sample_file(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_file
}
NAKED VOID __stdcall AIL_set_3D_sample_volume(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_volume
}
NAKED VOID __stdcall AIL_set_3D_sample_playback_rate(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_playback_rate
}
NAKED VOID __stdcall AIL_set_3D_sample_offset(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_offset
}
NAKED VOID __stdcall AIL_set_3D_sample_loop_count(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_loop_count
}
NAKED VOID __stdcall AIL_set_3D_sample_loop_block(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_loop_block
}
NAKED VOID __stdcall AIL_set_3D_sample_obstruction(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_obstruction
}
NAKED VOID __stdcall AIL_set_3D_sample_exclusion(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_exclusion
}
NAKED VOID __stdcall AIL_set_3D_sample_occlusion(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_occlusion
}
NAKED VOID __stdcall AIL_set_3D_sample_cone(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_cone
}
NAKED VOID __stdcall AIL_set_3D_sample_effects_level(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_effects_level
}
NAKED VOID __stdcall AIL_register_3D_EOS_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_3D_EOS_callback
}
NAKED VOID __stdcall AIL_3D_sample_obstruction(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_obstruction
}
NAKED VOID __stdcall AIL_3D_sample_exclusion(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_exclusion
}
NAKED VOID __stdcall AIL_3D_sample_occlusion(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_occlusion
}
NAKED VOID __stdcall AIL_3D_sample_cone(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_cone
}
NAKED VOID __stdcall AIL_3D_sample_effects_level(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_effects_level
}
NAKED VOID __stdcall AIL_3D_sample_status(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_status
}
NAKED VOID __stdcall AIL_3D_sample_volume(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_volume
}
NAKED VOID __stdcall AIL_3D_sample_playback_rate(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_playback_rate
}
NAKED VOID __stdcall AIL_3D_sample_offset(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_offset
}
NAKED VOID __stdcall AIL_3D_sample_length(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_length
}
NAKED VOID __stdcall AIL_3D_sample_loop_count(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_loop_count
}
NAKED VOID __stdcall AIL_set_3D_sample_distances(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_distances
}
NAKED VOID __stdcall AIL_3D_sample_distances(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_distances
}
NAKED VOID __stdcall AIL_set_3D_user_data(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_user_data
}
NAKED VOID __stdcall AIL_3D_user_data(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_user_data
}
NAKED VOID __stdcall AIL_active_3D_sample_count(BYTE)
{
	__asm JMP lpfn_AIL_active_3D_sample_count
}
NAKED VOID __stdcall AIL_3D_room_type(BYTE)
{
	__asm JMP lpfn_AIL_3D_room_type
}
NAKED VOID __stdcall AIL_set_3D_room_type(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_room_type
}
NAKED VOID __stdcall AIL_3D_speaker_type(BYTE)
{
	__asm JMP lpfn_AIL_3D_speaker_type
}
NAKED VOID __stdcall AIL_set_3D_speaker_type(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_speaker_type
}
NAKED VOID __stdcall AIL_3D_rolloff_factor(BYTE)
{
	__asm JMP lpfn_AIL_3D_rolloff_factor
}
NAKED VOID __stdcall AIL_set_3D_rolloff_factor(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_rolloff_factor
}
NAKED VOID __stdcall AIL_3D_doppler_factor(BYTE)
{
	__asm JMP lpfn_AIL_3D_doppler_factor
}
NAKED VOID __stdcall AIL_set_3D_doppler_factor(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_doppler_factor
}
NAKED VOID __stdcall AIL_3D_distance_factor(BYTE)
{
	__asm JMP lpfn_AIL_3D_distance_factor
}
NAKED VOID __stdcall AIL_set_3D_distance_factor(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_distance_factor
}
NAKED VOID __stdcall AIL_open_3D_listener(BYTE)
{
	__asm JMP lpfn_AIL_open_3D_listener
}
NAKED VOID __stdcall AIL_close_3D_listener(BYTE)
{
	__asm JMP lpfn_AIL_close_3D_listener
}
NAKED VOID __stdcall AIL_open_3D_object(BYTE)
{
	__asm JMP lpfn_AIL_open_3D_object
}
NAKED VOID __stdcall AIL_close_3D_object(BYTE)
{
	__asm JMP lpfn_AIL_close_3D_object
}
NAKED VOID __stdcall AIL_set_3D_position(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_position
}
NAKED VOID __stdcall AIL_set_3D_velocity(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_velocity
}
NAKED VOID __stdcall AIL_set_3D_velocity_vector(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_velocity_vector
}
NAKED VOID __stdcall AIL_set_3D_orientation(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_orientation
}
NAKED VOID __stdcall AIL_3D_position(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_position
}
NAKED VOID __stdcall AIL_3D_velocity(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_velocity
}
NAKED VOID __stdcall AIL_3D_orientation(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_orientation
}
NAKED VOID __stdcall AIL_update_3D_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_update_3D_position
}
NAKED VOID __stdcall AIL_auto_update_3D_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_auto_update_3D_position
}
NAKED VOID __stdcall AIL_size_processed_digital_audio(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_size_processed_digital_audio
}
NAKED VOID __stdcall AIL_process_digital_audio(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_process_digital_audio
}
NAKED VOID __stdcall AIL_merge_DLS_with_XMI(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_merge_DLS_with_XMI
}
NAKED VOID __stdcall AIL_compress_DLS(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_compress_DLS
}
NAKED VOID __stdcall AIL_filter_DLS_with_XMI(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_filter_DLS_with_XMI
}
NAKED VOID __stdcall AIL_compress_ASI(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_compress_ASI
}
NAKED VOID __stdcall AIL_decompress_ASI(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_decompress_ASI
}
NAKED VOID __stdcall AIL_request_EOB_ASI_reset(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_request_EOB_ASI_reset
}
NAKED VOID __stdcall AIL_set_redist_directory(BYTE)
{
	__asm JMP lpfn_AIL_set_redist_directory
}
NAKED VOID __stdcall MIX_RIB_MAIN(BYTE, BYTE)
{
	__asm JMP lpfn_MIX_RIB_MAIN
}
NAKED VOID __stdcall AIL_mem_use_malloc(BYTE)
{
	__asm JMP lpfn_AIL_mem_use_malloc
}
NAKED VOID __stdcall AIL_mem_use_free(BYTE)
{
	__asm JMP lpfn_AIL_mem_use_free
}
NAKED VOID AIL_sprintf(VOID)
{
	__asm JMP lpfnAIL_sprintf
}
NAKED VOID DLSMSSOpen(VOID)
{
	__asm JMP lpfnDLSMSSOpen
}
NAKED VOID DLSClose(VOID)
{
	__asm JMP lpfnDLSClose
}
NAKED VOID DLSLoadFile(VOID)
{
	__asm JMP lpfnDLSLoadFile
}
NAKED VOID DLSLoadMemFile(VOID)
{
	__asm JMP lpfnDLSLoadMemFile
}
NAKED VOID DLSGetInfo(VOID)
{
	__asm JMP lpfnDLSGetInfo
}
NAKED VOID DLSCompactMemory(VOID)
{
	__asm JMP lpfnDLSCompactMemory
}
NAKED VOID DLSUnloadAll(VOID)
{
	__asm JMP lpfnDLSUnloadAll
}
NAKED VOID DLSUnloadFile(VOID)
{
	__asm JMP lpfnDLSUnloadFile
}
NAKED VOID DLSSetAttribute(VOID)
{
	__asm JMP lpfnDLSSetAttribute
}
NAKED VOID __stdcall DLSMSSGetCPU(BYTE)
{
	__asm JMP lpfn_DLSMSSGetCPU
}

/*
//-------------------------------------------
// IJL.dll exports

NAKED void ijlGetLibVersion()
{
	__asm	jmp lpfnIJLGetLibVersion
}

NAKED void ijlInit()
{
	__asm	jmp lpfnIJLInit
}

NAKED void ijlFree()
{
	__asm	jmp lpfnIJLFree
}

NAKED void ijlRead()
{
	__asm	jmp lpfnIJLRead
}

NAKED void ijlWrite()
{
	__asm {
		PUSH	EBP
		MOV		EBP, ESP
		MOV		EAX, DWORD PTR SS:[EBP+8h]
		MOV		ECX, ssQuality
		MOV		DWORD PTR DS:[EAX+50h], ECX
		MOV		EDX, DWORD PTR SS:[EBP+0Ch]
		PUSH	EDX
		MOV		EAX, DWORD PTR SS:[EBP+08h]
		PUSH	EAX
		CALL	lpfnIJLWrite
		POP		EBP
		RETN
	}
}

NAKED void ijlErrorStr()
{
	__asm	jmp lpfnIJLErrorStr
}
*/